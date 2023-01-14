class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        return ((nums.size())*((nums.size())+1)/2) - total;
    }
};
