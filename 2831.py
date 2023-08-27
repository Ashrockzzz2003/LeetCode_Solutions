class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        freq_count = [0 for i in range(len(nums))]
        # find (i, j) such that (j - i + 1) is max and (j - i + 1 - frequency_of_max_occuring_element_in_subarray) is at most k)

        i = 0
        max_freq = -1

        for j in range(len(nums)):
            freq_count[nums[j] - 1] += 1
            max_freq = max(max_freq, freq_count[nums[j] - 1])

            if (j - i + 1 - max_freq > k):
                freq_count[nums[i] - 1] -= 1
                i += 1
            
        return max_freq

