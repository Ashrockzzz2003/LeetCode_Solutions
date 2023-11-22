class Solution:
    def findDiagonalOrder(self, nums):
        if (len(nums) == 1):
            return nums[0]
        
        n = len(nums)
        for i in range(len(nums)):
            n = max(n, len(nums[i]))

        sumDict = [[] for _ in range(2*n - 1)]
        
        for i in range(len(nums)):
            for j in range(len(nums[i])):
                sumDict[i+j] = [nums[i][j]] + sumDict[i+j]

        finalList = []
        for i in range(len(sumDict)):
            finalList += sumDict[i]

        return finalList

# class Solution:
#     def findDiagonalOrder(self, nums):
#         if (len(nums) == 1):
#             return nums[0]
        
#         n = len(nums)
#         for i in range(len(nums)):
#             n = max(n, len(nums[i]))

#         k = 1
#         finalList = [nums[0][0]]

#         while k != n:
#             k += 1
#             i = k - 1
#             j = 0
#             while i != -1 and j != k:
#                 try:
#                     finalList.append(nums[i][j])
#                     # print(k, (i, j), nums[i][j])
#                 except:
#                     continue
#                 finally:
#                     i -= 1
#                     j += 1
        
#         temp = k - 1
#         while (k != 2):
#             k -= 1
#             i = temp
#             j = n - k
#             while j != k + n - 1:
#                 try:
#                     finalList.append(nums[i][j])
#                     # print(k, (i, j), nums[i][j])
#                 except:
#                     continue
#                 finally:
#                     i -= 1
#                     j += 1
                

#         if len(nums) == n and len(nums[-1]) == n:
#             finalList.append(nums[n-1][n-1])

#         return finalList