

def cont_sum(arr, s):
    cur_sum, start = 0, 0

    for i in xrange(len(arr)):
        cur_sum += arr[i]
        print cur_sum

        if cur_sum == s:
            return (start, i)

        while cur_sum > s and start <= i:
            cur_sum -= arr[start]
            start += 1

    return None

print cont_sum(range(1, 101), 5050)
