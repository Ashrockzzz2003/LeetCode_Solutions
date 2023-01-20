class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26);

        for(auto &x: s) {
            arr[x - 'a'] += 1;
        }

        for(int i = 0; i < s.length(); i++) {
            if (arr[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
