# Write a program to detect conflicts in meeting schedules

import bisect

def number_conflicting(appts):
    appts = sorted(appts, key=lambda appt: appts[0])
    total = 0

    for i in xrange(len(appts)):
        ind = bisect.bisect_left(appts, (appts[i][1], None))
        total += ind - i - 1

    return total


appts = [(0, 3), (1, 5), (2, 6)]
print number_conflicting(appts)

appts = [(0, 3), (1, 5), (6, 7)]
print number_conflicting(appts)

appts = [(0, 3), (3, 5), (6, 7)]
print number_conflicting(appts)
