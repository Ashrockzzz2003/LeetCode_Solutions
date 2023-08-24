class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        
        longestNR = 0
        lastSeen = {}

        i = 0

        for j in range(len(s)):
            current = s[j]
            if current in lastSeen and lastSeen[current] >= i:
                i = lastSeen[current] + 1
            else:
                longestNR = max(longestNR, j - i + 1)
            lastSeen[current] = j
        
        return longestNR
