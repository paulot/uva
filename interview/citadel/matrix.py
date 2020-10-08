# Multiply 2 matrices

matrix1 = [[1,2,3],
           [4,5,6]]
matrix2 = [[7,8],[9,10],[11,12]]

def multiply(m1, m2):
    if len(m1) != len(m2[0]) or len(m1[0]) != len(m2):
        raise Exception('Matrix sizes dont match')

    ans = []
    for i in xrange(len(m1)):
        ans.append([])
        for j in xrange(len(m2[0])):
            val = 0
            for a in xrange(len(m1[0])):
                val += m1[i][a] * m2[a][j]
            ans[i].append(val)

    return ans

print multiply(matrix1, matrix2)
