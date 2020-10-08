import sys

matrix = [[1,2,3],[4,5,6],[7,8,9]]

def print_spiral(matrix):
    row, col = 0, 0
    row_len, col_len = len(matrix), len(matrix[0])

    while row < row_len and col < col_len:
        for i in xrange(col, col_len):
            sys.stdout.write('{0} '.format(matrix[row][i]))

        row += 1

        for i in xrange(row, row_len):
            sys.stdout.write('{0} '.format(matrix[i][col_len - 1]))

        col_len -= 1

        if row < row_len:
            for i in xrange(col_len - 1, col - 1, -1):
                sys.stdout.write('{0} '.format(matrix[row_len - 1][i]))
            row_len -= 1

        if col < col_len:
            for i in xrange(row_len - 1, row - 1, -1):
                sys.stdout.write('{0} '.format(matrix[i][col]))

            col += 1

print_spiral(matrix)
