class Solution {
public:
    int hammingWeight(uint32_t n) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        int count = 0;

        while (n) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};