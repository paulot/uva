# Given the alphabet encoded as numbers (e.g., a=1, b=2, ..., z=26), and a sequence of numbers
# (e.g., "23413259802"), how many strings can be generated.

def num_strings(nums):
    dp = [-1] * len(nums)
    def _num_strings(pos, nums):
        if pos == len(nums) or pos == len(nums) - 1:
            return 1
        if dp[pos] != -1:
            return dp[pos]

        if pos < len(nums) - 1 and nums[pos] * 10 + nums[pos + 1] <= 26:
            dp[pos] = _num_strings(pos + 1, nums) + _num_strings(pos + 2, nums)
        else:
            dp[pos] = _num_strings(pos + 1, nums)

        return dp[pos]
    return _num_strings(0, nums)


# print num_strings(0, [2, 2, 2])
print num_strings([2, 3, 4, 1, 3, 2])
print num_strings([1,1,1,1])
print num_strings([1,2,3,2,2,2,3,3,4,5,6,3,1,4,6,7,4,2,4,6,4,2,4,6,7,8,9,6,4,2,2,3,2,5,4,3,2,1,3,4,6,7,2])



'''
[2, 3, 4, 1, 3, 2]
[23, 4, 1, 3, 2]
[23, 4, 13, 2]
[2, 3, 4, 13, 2]

1 1 1 1
11 1 1
11 11
1 11 1
1 1 11
'''
