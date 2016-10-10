from random import randint as r
import sys
from itertools import permutations as p


for _ in xrange(0, 10):
  n, k = r(2, 10), r(900, 1000)
  print n, k

  for _ in xrange(0, n*(n-1)):
    d = r(1, 7)
    sys.stdout.write(str(d) + ' ')
    for _ in xrange(0, d):
      sys.stdout.write(str(r(0, 10)) + ' ')
    print

print 0, 0


