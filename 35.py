class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target > nums[-1]:
            return len(nums)
        if target < nums[0]:
            return 0
        if target == nums[-1]:
            return len(nums) - 1

        
        s = 0
        e = len(nums) - 1

        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] == target:
                return mid
            
            if nums[mid] > target:
                e = mid - 1
            else:
                s = mid + 1
        
        return s