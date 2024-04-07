#define ll long long

class Solution {
public:
    ll minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int m = n / 2; // the median

        ll minOps = abs(k - nums[m]);

        for(int i = m - 1; i >= 0; i--) {
            if (nums[i] < k) {
                break;
            }

            minOps += nums[i] - k;
        }

        for(int i = m + 1; i < n; i++) {
            if (nums[i] > k) {
                break;
            }

            minOps += k - nums[i];
        }
        
        return minOps;
        
    }
};