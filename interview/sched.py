import bisect

def num_conflicts(appts):
    appts = sorted(appts, key=lambda appt: appt[0])
    conflicts = 0

    for i in xrange(len(appts)):
        ind = bisect.bisect_left(appts, (appts[i][1], None))
        conflicts += ind - i - 1

    return conflicts

print num_conflicts([(1,4), (2, 3), (5, 6)])
print num_conflicts([(1,4), (2, 3), (5, 6), (4, 5), (9, 10)])
print num_conflicts([(1,4), (2, 3), (5, 6), (2, 4), (1, 5)])
