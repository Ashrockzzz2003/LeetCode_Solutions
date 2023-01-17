class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int size = 31;
        uint32_t reverse = n;
        n >>= 1;

        while(n) {
            reverse <<= 1;
            reverse |= n&1;
            n >>= 1;
            size--;
        }

        reverse <<= size--;
        return reverse;
    }
};
