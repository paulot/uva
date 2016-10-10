N = int(raw_input())
array = map(int, raw_input().split())
b = float(raw_input())
r, v, e, f = map(float, raw_input().split())

print b, r, f, e, v

time, dist = 0, 6
for x in range(dist):
  if x >= r:
    time += 1.0 / (v - e * (x - r))
  else:
    time += 1.0 / (v - f * (r - x))

print time
