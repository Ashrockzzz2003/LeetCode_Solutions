class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            nums[i] -=  int(str(nums[i])[::-1])

        nums.sort()
        
        total_pairs = 0

        i = 0
        while i < len(nums) - 1:
            current_n = 1
            if nums[i] == nums[i + 1]:
                while i < len(nums) - 1 and nums[i] == nums[i + 1]:
                    current_n += 1
                    i += 1
            
            i += 1
            total_pairs += ((current_n) * (current_n - 1)) // 2


        return total_pairs % (1000000007)

        