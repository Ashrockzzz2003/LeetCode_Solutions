class Solution:
    def editDistance(self, i, j, s1, s2, dp):
        if i < 0:
            return j + 1
        if j < 0:
            return i + 1

        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j]:
            dp[i][j] = self.editDistance(i - 1, j - 1, s1, s2, dp)
            return dp[i][j]
        
        insert = 1 + self.editDistance(i, j - 1, s1, s2, dp)
        delete = 1 + self.editDistance(i - 1, j, s1, s2, dp)
        replace = 1 + self.editDistance(i - 1, j - 1, s1, s2, dp)

        dp[i][j] = min(insert, delete, replace)
        return dp[i][j]

    def minDistance(self, s1: str, s2: str) -> int:
        dp = [[-1 for _ in range(len(s2))] for _ in range(len(s1))]
        return self.editDistance(len(s1) - 1, len(s2) - 1, s1, s2, dp)