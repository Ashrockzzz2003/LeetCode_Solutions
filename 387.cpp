class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> char_occurence_count(26, 0);

        for (int i = 0; i < s.length(); i++) {
            char_occurence_count[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (char_occurence_count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};