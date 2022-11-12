class Solution:
    def moveZeroes(self, arr: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(arr)):
            if(arr[i] == 0):
                arr.append(arr[i])
                arr.remove(arr[i])
