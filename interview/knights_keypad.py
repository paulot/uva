
keypad = {
    1: set([6, 8]),
    2: set([7, 9]),
    3: set([4, 8]),
    4: set([3, 9, 0]),
    5: set(),
    6: set([1, 7, 0]),
    7: set([2, 6]),
    8: set([1, 3]),
    9: set([2, 4]),
    0: set([4, 6])
}

dp = [[-1] * 101 for _ in xrange(0, 101)]
def moves(place, n):
    if n == 0:
        return 0

    if n == 1:
        return len(keypad[place])

    if dp[place][n] != -1:
        return dp[place][n]

    total = 0
    for neigh in keypad[place]:
        total += moves(neigh, n - 1)
    dp[place][n] = total
    return total

moves(1, 100)
