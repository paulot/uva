# Given an array of integers find a contiguous subset that sums to a given number

def subsum(arr, n):
    csum = 0
    start = 0

    for i in xrange(0, len(arr)):
        csum += arr[i]

        while csum > n and start < i:
            csum -= arr[start]
            start += 1

        if csum == n: return (start, i)

print subsum([15, 2, 4, 8, 9, 5, 10, 23], 23)
print subsum(range(2, 100, 2), 50)
print range(2, 100, 2)
