
def bestStrategy(grid):
    def solve(i, j):
        if grid[i][j] == 0: return;
        grid[i][j] = 0

        best = 1
        if i > 0 and grid[i-1][j] == 1:
            best += solve(i - 1, j)
        if i < len(grid) - 1 and grid[i+1][j] == 1:
            best += solve(i + 1, j)
        if j > 0 and grid[i][j - 1] == 1:
            best += solve(i, j - 1)
        if j < len(grid[0]) - 1 and grid[i][j + 1] == 1:
            best += solve(i, j + 1)

        return best

    ans = []
    for i in xrange(len(grid)):
        for j in xrange(len(grid[0])):
            if grid[i][j] == 1:
                ans.append((solve(i, j), i, j));
    return sorted(ans, reverse=True)

grid = [[1, 1, 1],
        [1, 0, 0],
        [1, 0, 1]]

print bestStrategy(grid)
