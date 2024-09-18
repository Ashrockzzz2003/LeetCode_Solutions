class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> string_nums;
        for(auto num : nums) string_nums.push_back(to_string(num));
        sort(string_nums.begin(), string_nums.end(), compare);

        string largest_num;
        for(string &num : string_nums) largest_num += num;
        return largest_num[0] == '0' ? "0" : largest_num;
    }
};