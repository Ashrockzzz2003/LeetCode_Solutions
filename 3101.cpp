class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        
        long long count = 0;
        long long left = 0, prev = nums[0];

        for (long long right = 1; right < nums.size(); right++) {
            if (nums[right] == prev) {
                left = max(left + 1, right);
            }
            prev = nums[right];
            count += right - left + 1;
        }

        return count + 1;
    }
};