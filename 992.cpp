class Solution {
public:
    int subarraysWithAtMostK(vector<int>& nums, int k) {
        unordered_map<int, int> currentFreq;

        int start_index = 0, end_index = 0;
        int good_subarrays = 0;

        while(end_index < nums.size()) {
            currentFreq[nums[end_index]]++;
            while (currentFreq.size() > k) {
                currentFreq[nums[start_index]]--;
                if (currentFreq[nums[start_index]] == 0) {
                    currentFreq.erase(nums[start_index]);
                }
                start_index++;
            }

            good_subarrays += (end_index - start_index + 1);
            end_index++;
        }

        return good_subarrays;

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        return subarraysWithAtMostK(nums, k) - subarraysWithAtMostK(nums, k - 1);
    }
};