# Given an array of integers find the sum of k largest integers in that array.

import bisect

def sumlargest(nums, k):
    k = min(len(nums), k)
    largest = [None]
    for num in nums:
        if num > largest[0]:
            bisect.insort(largest, num)

        if len(largest) > k:
            del largest[0]

    return largest

print sumlargest(range(99), 10)
