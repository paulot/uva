
import queue

def total_rooms(appts):
    appts, total = sorted(appts), 1
    room_available_at = queue.PriorityQueue()
    room_available_at.put(appts[0][1])

    for appt in appts[1:]:
        available_at = room_available_at.get()

        if appt[0] < available_at:
            total += 1
            room_available_at.put(available_at)

        room_available_at.put(appts[0][1])

    return total


appts = [(0, 3), (1, 5), (2, 6), (1, 3), (2, 3), (9, 10), (10, 11), (12, 13), (13, 14)]
print total_rooms(appts)

appts = [(0, 3), (1, 5), (6, 7)]
print total_rooms(appts)

appts = [(0, 3), (3, 5), (6, 7)]
print total_rooms(appts)


