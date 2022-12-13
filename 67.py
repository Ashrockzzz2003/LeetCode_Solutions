class Solution:
    def toBinary(self, n: int) -> int:
        return str(bin(n)[2:])
    
    def toDecimal(self, n: int) -> int:
        return int(n, 2)
    
    def addBinary(self, a: str, b: str) -> str:
        a = self.toDecimal(a)
        b = self.toDecimal(b)

        return self.toBinary(a + b)
