class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        rows, columns = len(grid), len(grid[0])
        onesRow = [0 for _ in range(rows)]
        onesCol = [0 for _ in range(columns)]

        diff = [[0 for _ in range(columns)] for _ in range(rows)]

        for i in range(rows):
            for j in range(columns):
                if grid[i][j] == 1:
                    onesRow[i] += 1
                    onesCol[j] += 1
        
        for i in range(rows):
            for j in range(columns):
                diff[i][j] = onesRow[i]*2 + onesCol[j]*2 - columns - rows


        return diff
                
