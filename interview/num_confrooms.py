

def num_confrooms(meetings):
    meetings = sorted(meetings, key=lambda meeting: meeting[1])
    num_rooms = 0
    queue = [meetings[0]]

    for meeting in meetings[1::]:
        while len(queue) > 0 and queue[0][1] < meeting[0]:
            queue.pop(0)

        queue.append(meeting)
        num_rooms = max(len(queue), num_rooms)

    return num_rooms

print num_confrooms([(1, 3), (4, 5), (2, 4)])
