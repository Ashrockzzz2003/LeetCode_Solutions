class Solution:
    # def lis(self, i, prev_i, nums, dp):
    #     if i == len(nums):
    #         return 0
        
    #     if dp[i][prev_i + 1] != -1:
    #         return dp[i][prev_i + 1]

    #     total_length = self.lis(i + 1, prev_i, nums, dp)

    #     if (prev_i == -1) or nums[i] > nums[prev_i]:
    #         total_length = max(total_length, 1 + self.lis(i + 1, i, nums, dp))


    #     dp[i][prev_i + 1] = total_length

    #     return dp[i][prev_i + 1]

    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [[0 for _ in range(len(nums) + 1)] for _ in range(len(nums) + 1)]

        for i in range(len(nums) - 1, -1, -1):
            for prev_i in range(i - 1, -2, -1):
                total_length = dp[i + 1][prev_i + 1]
                if (prev_i == -1) or nums[i] > nums[prev_i]:
                    total_length = max(total_length, 1 + dp[i + 1][i + 1])
                
                dp[i][prev_i + 1] = total_length
        
        return dp[0][0]

        # return self.lis(0, -1, nums, dp)
        