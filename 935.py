class Solution:
    def knightDialer(self, n: int) -> int:
        possible_moves = [[4, 6], [8, 6], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]

        dp = [[0 for _ in range(10)] for _ in range(n + 1)]
        for i in range(10):
            dp[0][i] = 1
        
        for i in range(1, n):
            for j in range(10):
                total = 0
                for v in possible_moves[j]:
                    total = total + dp[i - 1][v]
                
                dp[i][j] = total
        
        total = 0
        for i in range(10):
            total += dp[n - 1][i]
        
        return total % 1000000007




        