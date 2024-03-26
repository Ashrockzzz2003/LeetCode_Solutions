class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int minElement = INT_MAX, maxElement = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                minElement = min(nums[i], minElement);
                maxElement = max(nums[i], maxElement);
            }
        }

        if (minElement != 1) {
            return 1;
        }

        vector<bool> iAmPresent(nums.size() + 1, false);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] <= nums.size()) {
                iAmPresent[nums[i]] = true;
            }
        }

        for(int i = minElement; i < nums.size() + 1; i++) {
            if (iAmPresent[i] == false) {
                return i;
            }
        }

        return maxElement + 1;
    }
};