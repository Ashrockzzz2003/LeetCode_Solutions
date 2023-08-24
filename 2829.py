class Solution:
    def firstNSum(self, n):
        return n * (n + 1) // 2

    def minimumSum(self, n: int, k: int) -> int:
        if k >= 2*n:
            return self.firstNSum(n)
        
        return self.firstNSum(k // 2) + self.firstNSum(n - k // 2) + (n - k//2) * (k - 1)
                
                
        