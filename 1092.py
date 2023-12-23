class Solution:
    def SCSFromLCS(self, s1, s2):
        dp = [[0 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]

        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

        i = len(s1)
        j = len(s2)
        scs = ""

        while (i > 0 and j > 0):
            if (s1[i - 1] == s2[j - 1]):
                scs += s1[i - 1]
                i -= 1
                j -= 1
            elif dp[i][j - 1] >= dp[i - 1][j]:
                scs += s2[j - 1]
                j -= 1
            else:
                scs += s1[i - 1]
                i -= 1
        
        while (i > 0):
            scs += s1[i - 1]
            i -= 1
        
        while (j > 0):
            scs += s2[j - 1]
            j -= 1
        
        scs = scs[::-1]
        return scs

    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        return self.SCSFromLCS(str1, str2)
    

print(Solution().shortestCommonSupersequence("bbababbb", "bbbaaaba"))
        