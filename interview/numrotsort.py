
def rotbin(arr, x):
    start, end = 0, len(arr) - 1

    while start <= end:
        mid = (start + end) / 2

        if arr[mid] == x:
            return mid

        # First half is sorted
        if arr[start] <= arr[mid]:
            # Number is on the first half
            if arr[start] <= x and arr[mid] > x:
                end = mid - 1
            else:
                start = mid + 1
        # Second half is sorted
        else:
            if arr[end] >= x and arr[mid] < x:
                start = mid + 1
            else:
                end = mid - 1

    return -1


print rotbin(range(5, 10) + range(1, 5), 2)


