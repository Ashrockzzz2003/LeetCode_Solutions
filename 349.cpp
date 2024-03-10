class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> final_array;

        unordered_map<int, bool> isPresentInNumsOne = {};

        for (auto n : nums1) {
            isPresentInNumsOne[n] = true;
        }

        for (auto n: nums2) {
            if (isPresentInNumsOne[n] == true) {
                final_array.push_back(n);
                isPresentInNumsOne[n] = false;
            }
        }

        return final_array;
    }
};