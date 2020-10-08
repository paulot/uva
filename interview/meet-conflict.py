
import queue

def min_rooms(appts):
    q, total = queue.PriorityQueue(), 1
    appts = sorted(appts)
    print appts
    q.put(appts[0][1])

    for appt in appts[1:]:
        cur_end = q.get()

        if appt[0] < cur_end:
            total += 1
            q.put(cur_end)
            q.put(appt[1])
        else:
            q.put(appt[1])

    return total


appts = [(0, 3), (1, 5), (2, 6), (1, 3), (2, 3), (9, 10), (10, 11), (12, 13), (13, 14)]
print min_rooms(appts)

appts = [(0, 3), (1, 5), (6, 7)]
print min_rooms(appts)

appts = [(0, 3), (3, 5), (6, 7)]
print min_rooms(appts)


