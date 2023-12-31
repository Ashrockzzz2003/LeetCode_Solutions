class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        charDict = [-1 for _ in range(26)]
        
        for i in range(len(s)):
            if charDict[ord(s[i]) - 97] != -1:
                charDict[ord(s[i]) - 97] = min(i, charDict[ord(s[i]) - 97])
            else:
                charDict[ord(s[i]) - 97] = i
        
        maxSubstringLength = 0
        for i in range(len(s)):
            maxSubstringLength = max(maxSubstringLength, i - charDict[ord(s[i]) - 97])
        
        return maxSubstringLength - 1
