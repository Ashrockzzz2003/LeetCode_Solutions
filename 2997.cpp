class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int xor_total = 0;

        for(int i = 0; i < nums.size(); i++) xor_total ^= nums[i];

        int min_ops = 0;

        while(k || xor_total) {
            if (k % 2 != xor_total % 2) min_ops++;

            k /= 2;
            xor_total /= 2;
        }

        return min_ops;
    }
};