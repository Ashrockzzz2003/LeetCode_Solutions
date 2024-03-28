class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int start_index = -1;
        int window_size = 1;
        int max_window_size = 1;

        unordered_map<int, int> freq;

        for(int end_index = 0; end_index < s.length(); end_index++) {
            freq[s[end_index]]++;

            while (freq[s[end_index]] > 2) {
                start_index++;
                freq[s[start_index]]--;
            }

            max_window_size = max(max_window_size, end_index - start_index);
        }

        return max_window_size;
    }
};