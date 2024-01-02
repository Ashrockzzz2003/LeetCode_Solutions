class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        freqCount = [0 for _ in range(len(nums))]

        M = []

        for i in range(len(nums)):
            if freqCount[nums[i] - 1] >= len(M):
                M.append([])
            
            M[freqCount[nums[i] - 1]].append(nums[i])
            freqCount[nums[i] - 1] += 1

        
        return M

            
            
        