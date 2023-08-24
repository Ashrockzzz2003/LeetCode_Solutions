class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        if m == 0 or n == 0:
            return 0

        def DFS(i, j):
            grid[i][j] = 0

            if i + 1 < m and grid[i + 1][j] == '1':
                DFS(i + 1, j)
            if i > 0 and grid[i - 1][j] == '1':
                DFS(i - 1, j)
            if j + 1 < n and grid[i][j + 1] == '1':
                DFS(i, j + 1)
            if j > 0 and grid[i][j - 1] == '1':
                DFS(i, j - 1)
        
        islandCount = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    islandCount += 1
                    DFS(i, j)
        
        return islandCount

