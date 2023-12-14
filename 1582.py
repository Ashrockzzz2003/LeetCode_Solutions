class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows, columns = len(mat), len(mat[0])

        onesRow = [0 for _ in range(rows)]
        onesCol = [0 for _ in range(columns)]

        for i in range(rows):
            for j in range(columns):
                if mat[i][j] == 1:
                    onesRow[i] += 1
                    onesCol[j] += 1
        
        specialPositions = 0
        for i in range(rows):
            for j in range(columns):
                if mat[i][j] == 1 and onesRow[i] == 1 and onesCol[j] == 1:
                    specialPositions += 1
        
        return specialPositions
