


def subsum(subset, s):
    dp = [[-1] * len(subset) for _ in xrange(0, s + 1)]

    def subsetsum(subset, s, csum, cur):
        if cur == len(subset):
            return False

        if csum == s:
            return True

        if csum > s:
            return False

        if dp[csum][cur] != -1:
            return dp[csum][cur]

        dp[csum][cur] = subsetsum(subset, s, csum + subset[cur], cur + 1) or subsetsum(subset, s, csum, cur + 1)
        return dp[csum][cur]

    return subsetsum(subset, s, 0, 0)

def botsubsum(subset, s):
    dp = [[False] * (len(subset) + 1) for _ in xrange(0, s + 1)]

    for i in xrange(0, len(subset) + 1):
        dp[0][i] = True

    for csum in xrange(1, s + 1):
        for i in xrange(1, len(subset) + 1):
            if subset[i - 1] <= csum:
                dp[csum][i] = dp[csum - subset[i - 1]][i - 1] or dp[csum][i - 1]
            else:
                dp[csum][i] = dp[csum][i - 1]

    return dp[s][len(subset)]


print subsum([3, 34, 4, 12, 5, 2], 9), botsubsum([3, 34, 4, 12, 5, 2], 9)
print subsum([3, 34, 4, 12, 5, 2], 13), botsubsum([3, 34, 4, 12, 5, 2], 13)
