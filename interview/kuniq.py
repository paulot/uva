# Output a substring with at most k unique characters.

import collections
import copy

def kuniq(string, k):
    count = collections.defaultdict(lambda: 0)
    cur, best, num = collections.deque(), collections.deque(), 0

    for i in xrange(len(string)):
        cur.append(string[i])
        count[string[i]] += 1

        while len(count.keys()) > k:
            char = cur.popleft()
            count[char] -= 1

            if count[char] == 0:
                del count[char]

        if len(count.keys()) > num or (len(count.keys()) == num and len(cur) > len(best)):
            best = copy.copy(cur)
            num = len(count.keys())

    return ''.join(best), num

print kuniq('asdfasdfasdfasdfasdfasdfasdfasdf', 5)
print kuniq('asdfasdfasdfasdfasdfasdfasdfasdf', 4)
print kuniq('asdfasdfasdfasdfasdfasdfasdfasdf', 3)
print kuniq('asdfasdfasdfasdfasdfasdfasdfasdf', 2)
print kuniq('asdfasdfasdfasdfasdfasdfasdfasdf', 1)
print kuniq('asdfasdfasdfasdfasdfasdfasdfasdf', 0)
print kuniq('', 0)
