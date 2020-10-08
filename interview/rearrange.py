def rearrange(lis):
    start, end = 0, len(lis) - 1

    while lis[start] != 0:
        start += 1

    while lis[end] == 0:
        end -= 1

    while start < end:
        if lis[start] == 0:
            lis[start], lis[end] = lis[end], lis[start]
            end -= 1
        start += 1

    return lis

def rearrange_smart(lis):
    count = 0

    for i in lis:
        if i != 0:
            lis[count] = i
            count += 1

    for i in xrange(count, len(lis)):
        lis[i] = 0

    return lis


print rearrange([1,2,3,4,5,6,0,0,0,0,0,5,3])
print rearrange([0,0,0,0,0,0,0,2,3,4,6,4,3,1,3,0,0,0])
print rearrange_smart([1,2,3,4,5,6,0,0,0,0,0,5,3])
print rearrange_smart([0,0,0,0,0,0,0,2,3,4,6,4,3,1,3,0,0,0])
