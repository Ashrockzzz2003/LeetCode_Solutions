class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        total_ap_count = 0
        n = len(nums)
        dp = [defaultdict(int) for _ in range(n)]

        for i in range(1, n):
            for j in range(i):
                d = nums[i] - nums[j]
                dp[i][d] += 1
                if d in dp[j]:
                    dp[i][d] += dp[j][d]
                    total_ap_count += dp[j][d]
        
        return total_ap_count
