class Solution:
    def find_limit(self, strs: List[str]) -> str:
        limit = len(strs[0])
        for word in strs:
            if len(word) < limit:
                limit = len(word)
        
        return limit
    def longestCommonPrefix(self, strs: List[str]) -> str:
        limit = self.find_limit(strs)
        prefix = ""

        for i in range(limit+1):
            flag = True
            prefix = (strs[0])[:i]
            for j in range(len(strs)):
                if prefix != (strs[j])[:i]:
                    flag = False
                    prefix = (strs[0])[:i-1]
                    break
            if not flag:
                break
        
        return prefix
