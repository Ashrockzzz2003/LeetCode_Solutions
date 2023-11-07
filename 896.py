class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) <= 1:
            return True
        
        count_1 = 0
        count_2 = 0
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                count_1 += 1
            elif nums[i] > nums[i + 1]:
                count_2 += 1
            
            if (count_1 != 0 and count_2 != 0):
                return False
        
        return True