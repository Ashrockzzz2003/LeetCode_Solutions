class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0 for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):
            max_sum = arr[i]
            curr_max = 0
            for j in range(i, min(i + k, n)):
                max_sum = max(max_sum, arr[j])
                curr_max = max(curr_max, dp[j + 1] + (j - i + 1)*max_sum)
            dp[i] = curr_max
        
        return dp[0]