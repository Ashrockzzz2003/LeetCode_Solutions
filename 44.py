class Solution:
    def wildCardMatch(self, i, j, s, p, dp):
        if i < 0 and j < 0:
            return True
        
        if i < 0 and j >= 0:
            for k in range(j, -1, -1):
                if p[k] != "*":
                    return False
            
            return True
        
        if j < 0 and i >= 0:
            return False

        if dp[i][j] != None:
            return dp[i][j]

        # A single char match
        if s[i] == p[j] or p[j] == '?':
            dp[i][j] = self.wildCardMatch(i - 1, j - 1, s, p, dp)
            return dp[i][j]
        
        if p[j] == "*":
            dp[i][j] = self.wildCardMatch(i, j - 1, s, p, dp) or self.wildCardMatch(i - 1, j, s, p, dp)
            return dp[i][j]
        
        dp[i][j] = False
        return dp[i][j]


    def isMatch(self, s: str, p: str) -> bool:
        # ? -> match with Single Char
        # * -> match with sequence of length >= 0
        dp = [[None for _ in range(len(p))] for _ in range(len(s))]
        return self.wildCardMatch(len(s) - 1, len(p) - 1, s, p, dp)
        