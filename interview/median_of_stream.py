import bisect

def median(lis):
    if (len(lis) % 2 == 0): return (lis[len(lis) / 2] + lis[len(lis) / 2 - 1]) / 2.0
    else: return lis[len(lis) / 2]

def median_of_stream(stream):
    taken = []

    while len(stream) > 0:
        bisect.insort(taken, stream.pop(0))
        print 'Current median is', median(taken)

stream = range(1, 1000);
median_of_stream(stream)
