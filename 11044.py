import math
t = int(input())
grids = [map(int, input().split()) for _ in range(0, t)]
[print(bla) for bla in [int(math.ceil((i - 2) / 3)) * int(math.ceil((j - 2) / 3)) for (i, j) in grids]]
