class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq_map;

        for(int i = 0; i < n; i++) freq_map[nums[i]]++;

        int max_of_nums = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> greater_than_me_count;
        
        int cut_from_nums = 0;
        for(int i = 0; i <= max_of_nums; i++) {
            greater_than_me_count[i] = n - cut_from_nums;
            cut_from_nums += freq_map[i];
        }

        for(auto x : greater_than_me_count) {
            if (x.first == x.second) return x.first;
        }

        return -1;
    }
};