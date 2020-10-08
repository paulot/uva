import sys

matrix = [[1,2,3],[4,5,6],[7,8,9]]

def print_spiral(matrix):
    i, j, len_i, len_j = 0, 0, len(matrix), len(matrix[0])

    while i < len_i and j < len_j:
        for a in xrange(j, len_j):
            print matrix[i][a]
        i += 1

        for a in xrange(i, len_i):
            print matrix[a][len_j - 1]

        len_j -= 1

        if i < len_i:
            for a in xrange(len_j - 1, j - 1, -1):
                print matrix[len_i - 1][a]
            len_i -= 1

        if j < len_j:
            for a in xrange(len_i - 1, i - 1, -1):
                print matrix[a][j]
            j += 1

print_spiral(matrix)
