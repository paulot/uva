import argparse
import bisect
import collections
import logging

log = logging.getLogger(__name__)
logging.basicConfig()


class StockMarketMessage(object):
    """ Base class of all stock market messages. """

    def __init__(self, msg_type, timestamp, ticker, price):
        self.msg_type = msg_type
        self.timestamp = int(timestamp)
        self.ticker = ticker
        self.price = int(float(price) * 100)

    def __str__(self):
        return '{0} {1} {2} {3}'.format(self.msg_type, self.timestamp, self.ticker, self.price / 100)


class FillMessage(StockMarketMessage):
    """ Class describing a fill order. """

    def __init__(self, msg_type, timestamp, ticker, price, quantity, side):
        super().__init__(msg_type, timestamp, ticker, price)
        self.quantity = int(quantity)
        self.side = side

    def __str__(self):
        return '{0} {1} {2} {3} {4} {5}'.format(self.msg_type, self.timestamp, self.ticker, self.price / 100, self.quantity, self.side)

class PriceMessage(StockMarketMessage):
    """ Class defining a price update message. """

    def __init__(self, msg_type, timestamp, ticker, price):
        super().__init__(msg_type, timestamp, ticker, price)


class FileReader(object):
    """
    File parser to read stock market data and parse it into messages.
    Parses the input files and returns parsed messages in chronological order.

    Usage:
        for message in FileReader('price file', 'fills file').gen():
            Use the message
    """

    def __init__(self, prices_file_name, fills_file_name):
        """ Initializes the class, opens files. """

        self.prices_file = open(prices_file_name)
        self.fills_file = open(fills_file_name)
        self.prices = []
        self.fills = []
        self.inf = float('inf')

    def __del__(self):
        """ Closes the open file handles for the class. """

        self.prices_file.close()
        self.fills_file.close()

    def _update(self):
        """ Updates the messages that are present in the buffer. """

        if len(self.prices) == 0:
            line = self.prices_file.readline()

            if line:
                try:
                    self.prices.append(PriceMessage(*line.split()))
                except TypeError:
                    log.error('It seems like the prices file is malformed, please ensure the file is correctly structured.')
                    exit(1)

        if len(self.fills) == 0:
            line = self.fills_file.readline()

            if line:
                try:
                    self.fills.append(FillMessage(*line.split()))
                except TypeError:
                    log.error('It seems like the fills file is malformed, please ensure the file is correctly structured.')
                    exit(1)


    def gen(self):
        """ Return a generator for the parsed messages. """

        self._update()

        while len(self.fills) > 0 or len(self.prices):
            fill_time = self.inf if len(self.fills) == 0 else self.fills[0].timestamp
            price_time = self.inf if len(self.prices) == 0 else self.prices[0].timestamp

            if fill_time == self.inf and price_time == self.inf:
                raise StopIteration
            elif fill_time <= price_time:
                yield self.fills.pop()
            else:
                yield self.prices.pop()

            self._update()


class TraderPosition(object):
    """ Describes the positions we're currently holding for a particular stock. """

    def __init__(self, spent=0, quantity=0):
        self.total_spent = spent
        self.quantity = quantity

TRADER_POSITIONS = collections.defaultdict(lambda: TraderPosition())


def process_price_message(message):
    """ Processes a price update message. """

    profit = (TRADER_POSITIONS[message.ticker].quantity * message.price -
              TRADER_POSITIONS[message.ticker].total_spent)
    print('PNL {0} {1} {2} {3:.2f}'.format(message.timestamp, message.ticker,
                                           TRADER_POSITIONS[message.ticker].quantity, profit / 100))


def process_fill_message(message):
    """ Processes a fill message. """

    if message.side == 'B':
        TRADER_POSITIONS[message.ticker].total_spent += message.price * message.quantity
        TRADER_POSITIONS[message.ticker].quantity += message.quantity
    elif message.side == 'S':
        TRADER_POSITIONS[message.ticker].total_spent += message.price * (-message.quantity)
        TRADER_POSITIONS[message.ticker].quantity -= message.quantity
    else:
        log.error('Unknown side {0}. Please ensure all fill messages are valid buys/sells.'.format(message.side))
        exit(1)


def router(message):
    """ Routes a particular message to the correct handlers. """

    if isinstance(message, FillMessage):
        process_fill_message(message)
    elif isinstance(message, PriceMessage):
        process_price_message(message)
    else:
        log.error('Unkown message {0}. Please ensure all messages are either fills or price updates.'.format(message))
        exit(1)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('prices', help='File name of the prices file.')
    parser.add_argument('fills', help='File name of the filss file.')
    args = parser.parse_args()

    fr = FileReader(args.prices, args.fills)
    for msg in fr.gen():
        router(msg)

if __name__ == '__main__':
    main()
