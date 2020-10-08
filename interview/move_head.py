

def move_head(arr, num):
    count = 0

    for i in xrange(len(arr) - 1, -1, -1):
        if arr[i] != num:
            arr[len(arr) - count - 1] = arr[i]
            count += 1

    for i in xrange(0, len(arr) - count):
        arr[i] = num

    return arr

arr = [1,2,3,4,3,2,0,0,0,6,5,6,0]
print arr
print move_head(arr, 0)
