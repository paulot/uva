import bisect


class Elevator(object):
    def __init__(self, mode, last_floor, first_floor=1):
        self.mode = mode
        self.direction = None
        self.floors= []
        self.current_floor = first_floor
        self.first_floor = first_floor
        self.last_floor = last_floor
        self.timeout = 10

    def open_doors(self):
        self.mode = 'stand'

    def close_doors(self):
        self.mode = 'moving'

    def hold(self):
        self.open_doors()
        time.sleep(self.timeout)
        self.close_doors()

    def insert_floor(self, floor):
        bisect.insort(self.floors, floor)

    def run(self):
        while True:
            next_floor = bisect.bisect_left(self.floors, self.current_floor)

            if self.current_floor == self.floors[next_floor]:
                # Stop elevator here
                self.hold()
            elif self.direction == 'up':
                if next_floor == len(self.floors):
                    self.direction = 'down'
                    self.move(self.floors[next_floor - 1])
                else:
                    self.move(self.floors[next_floor])
            elif self.direction == 'down':
                if self.floors[next_floor - 1] < self.current_floor:
                    self.move(self.floors[next_floor])
                else:
                    self.direction = 'up'
                    self.move(self.floors[next_floor])






