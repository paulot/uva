

def longpal(string):
    longest = (0, 0)
    dp = [[None] * len(string) for _ in range(len(string))]

    def _longpal(i, j):
        nonlocal longest
        print(i, j)
        if i > j:
            return False
        if i == j:
            return True
        if i + 1 == j:
            return string[i] == string[j]
        if dp[i][j] != None:
            return dp[i][j]

        dp[i + 1][j - 1] = _longpal(i + 1, j - 1)
        dp[i][j] = string[i] == string[j] and dp[i + 1][j - 1]
        dp[i + 1][j] =  _longpal(i + 1, j)
        dp[i][j - 1] =  _longpal(i, j - 1)

        if dp[i][j] and j - i > longest[1] - longest[0]:
            longest = (i, j)
        elif dp[i + 1][j] and j - (i + 1) > longest[1] - longest[0]:
            longest = (i + 1, j)
        elif dp[i][j - 1] and (j - 1) - i > longest[1] - longest[0]:
            longest = (i, j - 1)

        return dp[i][j]

    _longpal(0, len(string) - 1)
    return longest


print(longpal('forgeeksskeegfor'))


