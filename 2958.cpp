class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int start_index = -1; // to mimick initial size of window to be 1.
        int window_size = 1;
        int max_window_size = 1;

        unordered_map<int, int> freq;

        for(int end_index = 0; end_index < nums.size(); end_index++) {
            freq[nums[end_index]]++;

            while (freq[nums[end_index]] > k) {
                start_index++;
                freq[nums[start_index]]--;
            }

            max_window_size = max(max_window_size, end_index - start_index);
        }

        return max_window_size;
    }
};