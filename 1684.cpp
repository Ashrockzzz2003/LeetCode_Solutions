class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> isValid(allowed.size(), 0);
        
        for(auto letter : allowed) {
            isValid[letter - 'a'] = true;
        }


        int consistent_strings = words.size();
        for(auto word : words) {
            for(auto letter : word) {
                if (!isValid[letter - 'a']) {
                    consistent_strings--;
                    break;
                }
            }
        }

        return consistent_strings;
    }
};