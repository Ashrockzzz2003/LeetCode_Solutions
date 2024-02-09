class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        
        n = len(nums)
        dp = [1 for _ in range(n)]
        prevElement = [-1 for _ in range(n)]
        maxIndex = 0

        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        prevElement[i] = j
            
            if dp[i] > dp[maxIndex]:
                maxIndex = i
        
        finalList = []

        while maxIndex != -1:
            finalList.append(nums[maxIndex])
            maxIndex = prevElement[maxIndex]
        
        return finalList
        


        
        