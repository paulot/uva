import sys

dp = [[1] + [0] * 301 for _ in range(1002)]
dp[1001][0] = 0

for coin in range(1, 301):
    for val in range(1, 301):
        if val < coin: dp[coin][val] = dp[coin - 1][val]
        else: dp[coin][val] = dp[coin - 1][val] + dp[coin][val - coin]

for line in sys.stdin:
    line = list(map(int, line.split()))
    if len(line) == 1:
        a = min(line[0], 300)
        print(dp[a][a])
    elif len(line) == 2:
        a, b = min(line[0], 300), min(line[1], 300)
        print(dp[b][a])
    elif len(line) == 3:
        a, b, c = min(line[0], 300), min(line[1] - 1, 300), min(line[2], 300)
        print(dp[c][a] - dp[b][a])
