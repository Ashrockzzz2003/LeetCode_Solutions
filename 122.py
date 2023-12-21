class Solution:
    # def maxP(self, i, canBuy, prices, dp):
    #     if i == len(prices):
    #         return 0
        
    #     if dp[i][canBuy] != -1:
    #         return dp[i][canBuy]

    #     if canBuy == 1:
    #         dp[i][canBuy] = max(self.maxP(i + 1, 0, prices, dp) - prices[i], self.maxP(i + 1, 1, prices, dp))
    #         return dp[i][canBuy]
    #     else:
    #         dp[i][canBuy] = max(self.maxP(i + 1, 1, prices, dp) + prices[i], self.maxP(i + 1, 0, prices, dp))
    #         return dp[i][canBuy]

    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        
        return profit
        