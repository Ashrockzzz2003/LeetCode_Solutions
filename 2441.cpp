class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // -3 -1 2 3

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            if (nums[start] == -nums[end]) {
                return nums[end];
            } else if (-nums[start] > nums[end]) {
                start++;
            } else {
                end--;
            }
        }

        return -1;

    }
};