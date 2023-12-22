class Solution:
    def maxScore(self, s: str) -> int:
        oneCount = 0
        zeroCount = 0

        best = -1

        for i in range(len(s) - 1):
            if s[i] == '1':
                oneCount += 1
            else:
                zeroCount += 1
        
            best = max(zeroCount - oneCount, best)
        
        if s[len(s) - 1] == '1':
            oneCount += 1
        
        return best + oneCount
        