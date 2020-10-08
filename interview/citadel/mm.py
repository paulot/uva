
matrix1 = [[1,2,3],
           [4,5,6]]
matrix2 = [[7,8],[9,10],[11,12]]

def mult(m1, m2):
    if len(m1[0]) != len(m2) or len(m1) != len(m2[0]):
        raise Exception('Matrix sizes dont match')

    m, n, ans = len(m2[0]), len(m1), []

    for i in xrange(n):
        ans.append([])
        for j in xrange(m):
            val = 0
            for k in xrange(len(m2)):
                val += m1[i][k] * m2[k][j]
            ans[i].append(val)

    return ans

print mult(matrix1, matrix2)


