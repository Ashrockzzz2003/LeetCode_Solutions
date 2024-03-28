class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue< pair<long long, long long> > heap;
        unordered_map<long long, long long> current_freq;

        vector<long long> most_freq_id_list;

        for(int i = 0; i < nums.size(); i++) {
            current_freq[nums[i]] += freq[i];
            heap.push({current_freq[nums[i]], nums[i]});

            while (heap.top().first != current_freq[heap.top().second]) {
                heap.pop();
            }

            most_freq_id_list.push_back(heap.top().first);
        }

        return most_freq_id_list;
    }
};