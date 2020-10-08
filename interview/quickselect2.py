


def partition(arr, start, end, pivot):
    val, larger = arr[pivot], start
    arr[end], arr[pivot] = arr[pivot], arr[end]

    for i in xrange(start, end):
        if arr[i] <= val:
            arr[i], arr[larger] = arr[larger], arr[i]
            larger += 1

    arr[end], arr[larger] = arr[larger], arr[end]
    return larger


def quickselect(arr, k):
    start, end = 0, len(arr) - 1

    while start <= end:
        pos = partition(arr, start, end, (start + end) / 2)

        if pos == k:
            return arr[pos]
        elif k < pos:
            end = pos - 1
        else:
            start = pos + 1


import random

for t in xrange(0, 100):
    n = random.randint(1, 1000)
    k = random.randint(0, n - 1)
    arr1 = [random.randint(-1000, 1000) for _ in xrange(n)]
    arr2 = arr1[:]
    assert quickselect(arr1, k) == sorted(arr2)[k]
