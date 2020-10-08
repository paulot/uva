

def rot90(matrix):
    ans = [[0] * len(matrix) for _ in xrange(len(matrix[0]))]

    for i in xrange(len(matrix)):
        for j in xrange(len(matrix[0])):
            ans[j][len(matrix) - i - 1] = matrix[i][j]

    return ans


def rot90counter(matrix):
    ans = [[0] * len(matrix) for _ in xrange(len(matrix[0]))]

    for i in xrange(len(matrix)):
        for j in xrange(len(matrix[0])):
            ans[len(matrix[0]) - j - 1][i] = matrix[i][j]

    return ans

def rot90inplace(matrix, n):
    for x in xrange(n / 2):
        for y in xrange(x, n - x - 1):
            tmp = matrix[x][y]
            matrix[x][y] = matrix[n - y - 1][x]
            matrix[n - y - 1][x] = matrix[n - x - 1][n - y - 1]
            matrix[n - x - 1][n - y - 1] = matrix[y][n - x - 1]
            matrix[y][n - x - 1] = tmp

    return matrix


matrix = [range(1, 10), range(4,13), range(10, 19)]
print rot90(matrix)
print rot90counter(matrix)
m = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
print
for r in m:
    print r
print
rot90inplace(m, 4)
for r in m:
    print r

