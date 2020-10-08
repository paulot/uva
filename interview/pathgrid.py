grid = [ '...*....',
         '...*....',
         '........']


def findPath(grid):
    visited = [[False] * len(grid[0]) for _ in xrange(len(grid))]

    def _findPath(grid, i, j, ei, ej):
        print i, j
        if i == ei and j == ej:
            return 0

        visited[i][j] = True

        best = 9999999999;
        if i > 0 and not visited[i-1][j] and grid[i-1][j] != '*':
            best = min(best, 1 + _findPath(grid, i-1, j, ei, ej))
        if i < len(grid) - 1 and not visited[i+1][j] and grid[i+1][j] != '*':
            best = min(best, 1 + _findPath(grid, i+1, j, ei, ej))
        if j > 0 and not visited[i][j-1] and grid[i][j-1] != '*':
            best = min(best, 1 + _findPath(grid, i, j-1, ei, ej))
        if j < len(grid[0]) - 1 and not visited[i][j+1] and grid[i][j+1] != '*':
            best = min(best, 1 + _findPath(grid, i, j+1, ei, ej))

        visited[i][j] = False
        return best

    return _findPath(grid, 0, 0, 0, len(grid[0]) - 1)


print findPath(grid)


