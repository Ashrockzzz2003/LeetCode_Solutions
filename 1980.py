class Solution:
    def invert(self, binary_bit):
        if binary_bit == "1":
            return "0"
        return "1"
    
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        diff_binary_string = ""
        for i in range(len(nums)):
            diff_binary_string += self.invert(nums[i][i])
        
        return diff_binary_string
        