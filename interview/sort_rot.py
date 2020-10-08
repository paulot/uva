import bisect


def search(arr, x):
    low, high = 0, len(arr) - 1

    while low < high:
        mid = (low + high) / 2

        if arr[mid] == x: return mid

        if arr[low] <= arr[mid]:
            # Beginning is sorted
            if arr[low] <= x and arr[mid] > x: high = mid - 1
            else: low = mid + 1
        else:
            if arr[mid] < x and arr[high] >= x: low = mid + 1
            else: low = mid - 1

    return low if low == high and arr[low] == x else -1


print search(range(5, 10) + range(1, 5), 2)
