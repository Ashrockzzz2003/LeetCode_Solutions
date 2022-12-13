class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        s = s.split(" ")
        for i in range(len(s)):
            if " " in s[i]:
                s[i].replace(" ", "")
        if "" in s:
            s.remove("")
        return len(s[-1])
