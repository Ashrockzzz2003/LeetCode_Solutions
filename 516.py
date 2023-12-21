class Solution:
    def lcs(self, s1, s2):
        dp = [[0 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]

        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        
        return dp[len(s1)][len(s2)]

    def longestPalindromeSubseq(self, s: str) -> int:
        reversed_s = s[::-1]

        return self.lcs(s, reversed_s)

        