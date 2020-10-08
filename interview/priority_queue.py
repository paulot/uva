import bisect

class PriorityQueue(object):
    def __init__(self, key=lambda a: a):
        self.key = key
        self.items = []
        self.keys = []

    def insert(self, item):
        key = self.key(item)
        insertion_point = bisect.bisect_left(self.keys, key)
        self.keys.insert(insertion_point, key)
        self.items.insert(insertion_point, item)

    def top(self):
        if len(self.items) > 0:
            return self.items[0]

    def pop(self):
        if len(self.items) > 0:
            self.items.pop(0)

def test_min_heap():
    """ Should function as a min heap. """

    bla = PriorityQueue(key=lambda a: a)

    for i in xrange(0, 100):
        bla.insert(i)

    for i in xrange(0, 100):
        assert bla.top() == i, 'got: {0} expected: {1}'.format(bla.top(), i)
        bla.pop()

def test_max_heap():
    """ Should function as a max heap. """

    bla = PriorityQueue(key=lambda a: -a)

    for i in xrange(0, 100):
        bla.insert(i)

    for i in xrange(0, 100):
        assert bla.top() == 99 - i, 'got: {0} expected: {1}'.format(bla.top(), 99 - i)
        bla.pop()

def test_none_when_empty():
    """ Should return None when the queue is empty. """

    bla = PriorityQueue()
    assert bla.top() is None


test_min_heap()
test_max_heap()
test_none_when_empty()
