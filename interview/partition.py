
def partition(arr, num):
    store_ind = 0

    for i in xrange(0, len(arr)):
        if arr[i] == num:
            arr[store_ind], arr[i] = arr[i], arr[store_ind]
            store_ind += 1

    return arr

print partition([3,2,5,3,3,2,5,6,0,0,0,3,4,5,0], 0)
