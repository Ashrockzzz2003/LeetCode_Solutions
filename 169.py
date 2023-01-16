class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 0
        
        for i in d:
            if d[i] >= len(nums) // 2:
                return i
        
        return -1
