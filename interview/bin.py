import math


def binn(n):
    ans = []

    while n:
        print n, bin(n)
        ans.append('1' if n % 2 == 1 else '0')
        n = (n >> 1) ^ (1 << 32)
    return ''.join(reversed(ans))


for i in xrange(-10, 50):
    print binn(i)
