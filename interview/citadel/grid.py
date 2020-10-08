# Find the number of ways to get from the leftmost top
# of a n, m grid to the bottom

def number_of_ways(n, m):
    dp = [[0] * m for _ in xrange(n)]

    for i in xrange(m):
        dp[0][i] = 1

    for i in xrange(n):
        dp[i][0] = 1


    for i in xrange(1, n):
        for j in xrange(1, m):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]

    return dp[i][j]






print number_of_ways(4, 4)

