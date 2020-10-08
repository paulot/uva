import sys
import bisect

arr = []

for line in sys.stdin:
    n = int(line)
    bisect.insort(arr, n)
    if len(arr) % 2 == 1: print(arr[len(arr)//2])
    else: print ((arr[len(arr)//2] + arr[len(arr)//2 - 1]) // 2)
