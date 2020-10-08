
def iterate_sorted(arrs):
    ind = 0

    while len(arrs) > 0:
        for i in xrange(len(arrs)):
            if arrs[i][0] < arrs[ind][0]:
                ind = i
        yield arrs[ind].pop(0)

        if len(arrs[ind]) == 0:
            arrs.pop(ind)
            ind = 0

for num in iterate_sorted([range(1, 10), range(4, 50, 4), range(2, 20, 2)]):
    print num
