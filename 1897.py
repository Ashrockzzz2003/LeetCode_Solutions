class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        # Count of characters should be a multiple of number of words!
        # Only 26 lowercase characters. Let's use an array

        charCount = [0 for _ in range(26)]
        n = len(words)

        for word in words:
            for letter in word:
                charCount[ord(letter) - 97] += 1
        
        for count in charCount:
            if count % n != 0:
                return False
        
        return True
