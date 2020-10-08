# You have a string of numbers, i.e. 123. You can insert a + or - sign in front of ever number,
# or you can leave it empty. Find all of the different possibilities, make the calculation and return the sum.

dp = {}
def sum_iter(string, i):
    if string not in dp: dp[string] = [None] * (len(string) + 1)
    if i == len(string) + 1: return 0
    if string in dp and dp[string][i] is not None: return dp[string][i]

    csum = 0
    for j in xrange(i + 1, len(string) + 1):
        csum += int(string[i:j]) + sum_iter(string, j)

    dp[string][i] = csum
    return csum


print sum_iter('12312121211213', 0)



