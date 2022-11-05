class Solution:
    def isPalindrome(self, x: int) -> bool:
        key = str(x)
        for i in range(len(key)):
            if key[i] != key[len(key) - 1 - i]:
                return False
        return True
