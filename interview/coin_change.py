def make_change(num, coins):
    dp = [1] + [0] * num

    for coin in coins:
        for n in xrange(coin, num + 1):
            dp[n] += dp[n - coin]

    return dp[num]

print make_change(4, [1, 2, 3])
