# Brute Force
# class Solution:
#     def strStr(self, haystack: str, needle: str) -> int:
#         if len(needle) > len(haystack):
#             return -1

#         if len(haystack) == len(needle):
#             return 0 if haystack == needle else -1

#         k = len(needle)
#         for i in range(len(haystack)):
#             if needle in haystack[0:k]:
#                 return i
#             else:
#                 k += 1
        
#         return -1

# Boyer Moore Algorithm
class Solution:
    def buildLast(self, text, pattern):
        last_occurence = {}
        for i in range(len(text)):
            last_occurence[text[i]] = -1
        
        for i in range(len(pattern)):
            last_occurence[pattern[i]] = i
        
        return last_occurence
    
    def strStr(self, text: str, pattern: str) -> int:
        n = len(text)
        m = len(pattern)
        last = self.buildLast(text, pattern)

        i = m - 1
        j = m - 1

        while (i < n):
            if text[i] == pattern[j]:
                if j == 0:
                    return i
                else:
                    i -= 1
                    j -= 1
            else:
                i = i + m - min(j, last[text[i]] + 1)
                j = m - 1
        
        return -1

# KMP

# class Solution:
#     def build_failure_function(self, pattern):
#         f = [0 for _ in range(len(pattern))]

#         i = 1
#         j = 0

#         while i < len(pattern):
#             if pattern[i] == pattern[j]:
#                 f[i] = j + 1
#                 i += 1
#                 j += 1
#             elif j > 0:
#                 j = f[j - 1]
#             else:
#                 f[i] = 0
#                 i += 1
        
#         return f
    
#     def strStr(self, text: str, pattern: str) -> int:
#         n = len(text)
#         m = len(pattern)
        
#         f = self.build_failure_function(pattern)

#         i = 0
#         j = 0

#         while i < n:
#             if text[i] == pattern[j]:
#                 if j == m - 1:
#                     return i - m + 1
#                 else:
#                     i += 1
#                     j += 1
#             elif j > 0:
#                 j = f[j - 1]
#             else:
#                 i += 1

#         return -1


