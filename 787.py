import sys

for line in sys.stdin:
    nums = list(map(int, line.split()))[:-1]
    best, cur = nums[0], 1
    for i in range(0, len(nums)):
        cur = 1
        for j in range(i, len(nums)):
            cur *= nums[j]
            best = max(cur, best)
    print(best)
