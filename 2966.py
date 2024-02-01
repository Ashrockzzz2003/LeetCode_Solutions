class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()

        final_array = []

        i = 0
        for _ in range(n // 3):
            if nums[i + 2] - nums[i] > k:
                return []
            
            final_array.append([nums[i], nums[i + 1], nums[i + 2]])
            i += 3
        
        return final_array
