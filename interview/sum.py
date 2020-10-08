def contsum(s, nums):
    csum, start = 0, 0

    for i in xrange(0, len(nums)):
        csum += nums[i]

        while csum > s:
            csum -= nums[start]
            start += 1

        if csum == s:
            return (start, i)

    return None

print contsum(10, [1,2,3,44,5,6,1,1,1,1,7,8,3,5,6,3])
