def move_num(arr, num):
    count = 0

    for i in xrange(len(arr)):
        if arr[i] != num:
            arr[count] = arr[i]
            count += 1

    for i in xrange(count, len(arr)):
        arr[i] = num

    return arr

import random
rarr = lambda: [random.randint(1, 10) for _ in xrange(random.randint(1, 20))]
print move_num(rarr(), 4)
