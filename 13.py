class Solution:
    def romanToInt(self, s: str) -> int:
        ROMAN = {'M': 1000, 'CM': 900, 'D': 500, 'CD': 400, 'C': 100, 'XC': 90, 'L': 50, 'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1}
        n = 0
        for i in range(len(s)):
            if i != len(s) - 1 and ROMAN[s[i]] < ROMAN[s[i+1]]:
                n -= ROMAN[s[i]]
            else:
                n += ROMAN[s[i]]
        
        return n
