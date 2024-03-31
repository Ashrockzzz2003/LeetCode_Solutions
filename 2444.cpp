class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long sub_array_count = 0;
        long long minKIndex = -1, maxKIndex = -1, start_index = -1;

        for(long long i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                start_index = i;
            }

            if (nums[i] == minK) {
                minKIndex = i;
            }
            if (nums[i] == maxK) {
                maxKIndex = i;
            }

            if (min(maxKIndex, minKIndex) - start_index > 0) {
                sub_array_count += min(maxKIndex, minKIndex) - start_index; 
            }
        }

        return sub_array_count;
    }
};