class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        if sum(nums) < target:
            return -1

        # As it's already given max nums is 2^30, 32 bits will work. Just for Regularity.
        # First let's find what we have in terms of bits.

        target_bin = bin(target)[2:]
        
        freq_count = [0 for _ in range(32)]
        for n in nums:
            # bit_length returns 3 for 4 2^2 => 110, so len(110) - 1 is what we get here
            freq_count[n.bit_length() - 1] += 1

        min_ops = 0
        for i in range(31):
            # If I want that ith_bit
            if i < len(target_bin) and target_bin[len(target_bin) - 1 - (i)] == '1':
            # if ((target >> i) & (1)):
                # We already have the bit we wanted. Let's use it.
                if freq_count[i] > 0:
                    freq_count[i] -= 1
                # 2^i is missing.
                else:
                    for j in range(i + 1, 32):
                        if freq_count[j] > 0:
                            freq_count[j] -= 1
                            # number of division ops that'll happen max to get 2^i.
                            min_ops += j - i
                            # 2^(i) to 2^(j-1) gets a new copy.
                            for x in range(i, j):
                                freq_count[x] += 1
                            break
            
            
            freq_count[i + 1] += freq_count[i] // 2
        
        return min_ops
