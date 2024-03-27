class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // Less than 1 is possible only when nums has element 0.
        // But constraints tell us that nums[i] is atleast 1.
        if (k <= 1) {
            return 0;
        }

        int start_index = 0, end_index = 0;
        int current_product = 1, our_subarrays = 0;

        while (end_index < nums.size()) {
            current_product *= nums[end_index];
            end_index++;

            while(start_index < end_index && current_product >= k) {
                current_product /= nums[start_index];
                start_index++;
            }

            our_subarrays += (end_index - start_index);
        }

        return our_subarrays;
    }
};