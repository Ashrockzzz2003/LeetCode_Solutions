class Solution:    
    def climbStairs(self, n: int) -> int:
        fibo = [1, 1]
        for i in range(n - 1):
            fibo[0], fibo[1] = fibo[1], fibo[0] + fibo[1]
        return fibo[1]
