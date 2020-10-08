
def sumtarget(arr, target):
    nums = set(arr)

    for num in arr:
        if target - num in nums:
            return (num, target - num)

    return None

def sum3target(arr, target):
    arr = sorted(arr)

    for i in xrange(len(arr) - 2):
        start, end = i + 1, len(arr) - 1

        while start < end:
            if arr[i] + arr[start] + arr[end] == target:
                return arr[i], arr[start], arr[end]
            elif arr[i] + arr[start] + arr[end] < target:
                start += 1
            else:
                end -= 1

def sumktarget(arr, target, k):
    dp = [[[-1] * (k + 1) for _ in xrange(target + 1)] for _ in xrange(len(arr))]

    def _sumktarget(arr, pos, target, k):
        if target == 0 and k == 0:
            return []
        if pos >= len(arr) or k == 0 or target < 0:
            return None
        if dp[pos][target][k] != -1:
            return dp[pos][target][k]

        sol = _sumktarget(arr, pos + 1, target - arr[pos], k - 1)

        if sol != None:
            dp[pos][target][k] = [arr[pos]] + sol
        else:
            dp[pos][target][k] = _sumktarget(arr, pos + 1, target, k)

        return dp[pos][target][k]
    return _sumktarget(arr, 0, target, k)


'''
print sumktarget(range(3, 10), 32, 5)
'''

for i in xrange(300, 2000, 200):
    print sumktarget(range(3, 100), i, 10), i

