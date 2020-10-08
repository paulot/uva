import sys

matrix = [[1,2,3],[4,5,6],[7,8,9]]


def print_spiral(matrix):
    cur_row, cur_col, len_row, len_col = 0, 0, len(matrix), len(matrix[0])

    while cur_row < len_row and cur_col < len_col:
        for i in xrange(cur_col, len_col):
            sys.stdout.write('{0} '.format(matrix[cur_row][i]))
        cur_row += 1

        for i in xrange(cur_row, len_row):
            sys.stdout.write('{0} '.format(matrix[i][len_col - 1]))
        len_col -= 1

        if cur_row < len_row:
            for i in xrange(len_col - 1, cur_col - 1, -1):
                sys.stdout.write('{0} '.format(matrix[len_row - 1][i]))
            len_row -= 1

        if cur_col < len_col:
            for i in xrange(len_row - 1, cur_row - 1, -1):
                sys.stdout.write('{0} '.format(matrix[i][cur_col]))
            cur_col += 1
print_spiral(matrix)
