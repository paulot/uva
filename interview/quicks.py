

def partition(arr, start, end, pivot):
    val = arr[pivot]
    store = start
    arr[end], arr[pivot] = arr[pivot], arr[end]

    for i in xrange(start, end):
        if arr[i] <= val:
            arr[store], arr[i] = arr[i], arr[store]
            store += 1

    arr[store], arr[end] = arr[end], arr[store]
    return store


def quickselect(arr, k):
    start, end = 0, len(arr) - 1

    while start <= end:
        pos = partition(arr, start, end, (start + end) / 2)

        if k == pos:
            return arr[pos]
        elif k > pos:
            start = pos + 1
        else:
            end = pos - 1





import random

for t in xrange(0, 100):
    n = random.randint(1, 1000)
    k = random.randint(0, n - 1)
    arr1 = [random.randint(-1000, 1000) for _ in xrange(n)]
    arr2 = arr1[:]
    assert quickselect(arr1, k) == sorted(arr1)[k]

    # assert quickselect(arr1, 0, n - 1, k) == quickiter(arr2, k) == sorted(arr3)[k]
