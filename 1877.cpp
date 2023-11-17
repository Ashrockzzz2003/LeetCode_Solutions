class Solution {
public:
    int minPairSum(vector<int>& nums) {
    
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());

        int min_max_pair_sum = 0;

        for(int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] + nums[nums.size() - 1 - i] > min_max_pair_sum) {
                min_max_pair_sum = nums[i] + nums[nums.size() - 1 - i];
            }
        }

        return min_max_pair_sum;
    }
};