#define ll long long

class Solution {
public:
    ll countSubarrays(vector<int>& nums, int k) {
        ll max_guy = *max_element(nums.begin(), nums.end());

        vector<ll> max_occurs_at;

        ll total_no_of_subarrays = 0;

        for (ll i = 0; i < nums.size(); i++) {
            if (nums[i] == max_guy) {
                max_occurs_at.push_back(i);
            }

            if (max_occurs_at.size() >= k) {
                total_no_of_subarrays += max_occurs_at[max_occurs_at.size() - k] + 1;
            }
        }

        return total_no_of_subarrays;
    }
};