

def spiral(matrix):
    i, j = len(matrix) / 2, (len(matrix) - 1) / 2

    print matrix[i][j]
    j += 1

    for l in xrange(2, len(matrix) + 1, 2):
        for ii in xrange(0, l):
            print matrix[i - ii][j]

        i -= l - 1
        j -= 1

        for ii in xrange(0, l):
            print matrix[i][j - ii]

        j -= l - 1
        i += 1

        for ii in xrange(0, l):
            print matrix[i + ii][j]

        i += l - 1
        j += 1

        for ii in xrange(0, l):
            print matrix[i][j + ii]

        j += l - 1
        i -= 1


m = [[ 1,2,3,4,5,6],
     [20,21,22,23,24,7],
     [19,32,33,34,25,8],
     [18,31,36,35,26,9],
     [17,30,29,28,27,10],
     [16,15,14,13,12,11]]
spiral(m)
