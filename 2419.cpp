class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = 0, sub_array_size = 0, longest_sub_array_size = 0;

        for(auto &num : nums) {
            if (max_num == 0 || max_num < num) {
                max_num = num;
                longest_sub_array_size = 1;
                sub_array_size = 1;
            } else if (max_num == num) {
                sub_array_size++;
                longest_sub_array_size = max(longest_sub_array_size, sub_array_size);
            } else {
                sub_array_size = 0;
            }
        }

        return longest_sub_array_size;
    }
};