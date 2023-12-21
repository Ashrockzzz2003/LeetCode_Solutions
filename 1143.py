class Solution:
    def lcs(self, i, j, s1, s2, dp):
        if i < 0 or j < 0:
            return 0
        
        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j]:
            dp[i][j] = 1 + self.lcs(i - 1, j - 1, s1, s2, dp)
        else:
            dp[i][j] = max(self.lcs(i - 1, j, s1, s2, dp), self.lcs(i, j - 1, s1, s2, dp))
        
        return dp[i][j]
    
    def lcsDP(self, s1, s2):
        dp = [[0 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]

        # for i in range(len(s1)):
        #     dp[i][0] = 0
        
        # for j in range(len(s2)):
        #     dp[0][j] = 0
        
        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        
        return dp[len(s1)][len(s2)]

    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        # dp = [[-1 for _ in range(len(s2))] for _ in range(len(s1))]
        # return self.lcs(len(s1) - 1, len(s2) - 1, s1, s2, dp)

        return self.lcsDP(s1, s2)

        