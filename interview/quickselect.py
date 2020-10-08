def partition(arr, start, end, pivotInd):
    pivot = arr[pivotInd]
    arr[end], arr[pivotInd] = arr[pivotInd], arr[end]
    storeInd = start
    for i in xrange(start, end):
        if arr[i] <= pivot:
            arr[storeInd], arr[i] = arr[i], arr[storeInd]
            storeInd += 1
    arr[storeInd], arr[end] = arr[end], arr[storeInd]
    return storeInd


def quickiter(arr, k):
    start, end = 0, len(arr) - 1

    while start <= end:
        mid = (start + end) / 2
        pos = partition(arr, start, end, mid)

        if pos == k:
            return arr[pos]
        elif pos < k:
            start = pos + 1
        else:
            end = pos - 1
    return -1

def quickselect(arr, start, end, k):
    if start == end:
        return arr[start]

    pivotInd = (start + end) / 2
    pos = partition(arr, start, end, pivotInd)

    if pos == k:
        return arr[pos]
    elif pos < k:
        return quickselect(arr, pos + 1, end, k)
    else:
        return quickselect(arr, start, pos - 1, k)


import random

for t in xrange(0, 100):
    n = random.randint(1, 1000)
    k = random.randint(0, n - 1)
    arr1 = [random.randint(-1000, 1000) for _ in xrange(n)]
    arr2 = arr1[:]
    arr3 = arr1[:]
    assert quickselect(arr1, 0, n - 1, k) == quickiter(arr2, k) == sorted(arr3)[k]
