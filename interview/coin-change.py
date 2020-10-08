def coin_change(denon, k):
    dp = [1] + [0] * k
    for coin in denon:
        for val in xrange(coin, k):
            dp[val] += dp[val - coin]
    return dp[k]
