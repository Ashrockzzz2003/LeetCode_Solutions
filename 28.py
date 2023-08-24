class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) > len(haystack):
            return -1

        if len(haystack) == len(needle):
            return 0 if haystack == needle else -1

        k = len(needle)
        for i in range(len(haystack)):
            if needle in haystack[0:k]:
                return i
            else:
                k += 1
        
        return -1