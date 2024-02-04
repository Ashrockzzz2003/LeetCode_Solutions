class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max = nums[0]
        curr_min = nums[0]
        max_product = nums[0]

        for i in range(1, len(nums)):
            old_curr_max = curr_max
            curr_max = max(nums[i], curr_max*nums[i], curr_min*nums[i])
            max_product = max(curr_max, max_product)
            curr_min = min(nums[i], curr_min*nums[i], old_curr_max*nums[i])
        
        return max_product
