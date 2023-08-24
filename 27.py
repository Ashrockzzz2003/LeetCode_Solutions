class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums.sort()

        k = 0
        start_index = None

        for i in range(len(nums)):
            if nums[i] != val:
                k += 1
            elif start_index == None:
                start_index = i

        if start_index != None:
            i = start_index
            j = len(nums) - 1

            # 0 0 1 2 2 2 3 4
            #       i       j
            # 0 0 1 4 2 2 3 2
            #         i   j  
            # 0 0 1 4 3 2  2 2
            # 0 0 1 4 3 ij

            while i <= len(nums) - 1 and j >= 0 and i < j and i != j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
            
        return k
