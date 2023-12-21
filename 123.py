class Solution:
    # def maxP(self, i, canBuy, cap, prices, dp):
    #     if cap == 0:
    #         return 0
        
    #     if i == len(prices):
    #         return 0

    #     if dp[i][canBuy][cap] != -1:
    #         return dp[i][canBuy][cap]

    #     if canBuy == 1:
    #         # Buy or not Buy
    #         dp[i][canBuy][cap] = max(-prices[i] + self.maxP(i + 1, 0, cap, prices, dp), self.maxP(i + 1, 1, cap, prices, dp))
    #         return dp[i][canBuy][cap]
    #     else:
    #         # Sell or not sell
    #         dp[i][canBuy][cap] = max(self.maxP(i + 1, 1, cap - 1, prices, dp) + prices[i], self.maxP(i + 1, 0,  cap, prices, dp))
    #         return dp[i][canBuy][cap]

    def maxProfit(self, prices: List[int]) -> int:
        dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(len(prices) + 1)]

        for i in range(len(prices) - 1, -1, -1):
            for canBuy in range(2):
                for cap in range(1, 3):
                    if canBuy == 1:
                        # Buy or not Buy
                        dp[i][canBuy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap])
                    else:
                        # Sell or not sell
                        dp[i][canBuy][cap] = max(dp[i + 1][1][cap - 1] + prices[i], dp[i + 1][0][cap])

        return dp[0][1][2]
        