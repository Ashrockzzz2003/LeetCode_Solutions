class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)

        sorted_s = sorted(freq, key = lambda char: -freq[char])

        final_s = ""
        for char in sorted_s:
            final_s += char * freq[char]
        
        return final_s

        