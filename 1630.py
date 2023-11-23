class Solution:
    def isArithmetic(self, nums):
        nums.sort()
        for i in range(2, len(nums)):
            if nums[i] - nums[i - 1] != nums[1] - nums[0]:
                return False
        
        return True


    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        final_ans = []
        for i in range(len(l)):
            final_ans.append(self.isArithmetic(nums[l[i]:r[i] + 1]))
        
        return final_ans
        