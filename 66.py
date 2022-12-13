class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        w = int("1" + "0"*(len(digits)-1))
        s = 0
        for i in range(len(digits)):
            s += digits[i]*w
            w //= 10
        
        s += 1
        digits = list(str(s))
        for i in range(len(digits)):
            digits[i] = int(digits[i])
        
        return digits
