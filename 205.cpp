class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> char_map;
        unordered_map<char, bool> map_done;

        for(int i = 0; i < s.length(); i++) {
            if (char_map.find(s[i]) == char_map.end() && (map_done.find(t[i]) == map_done.end() || map_done[t[i]] == false)) {
                char_map[s[i]] = t[i];
                map_done[t[i]] = true;
            }
        }

        for(int i = 0; i < s.length(); i++) {
            if (char_map[s[i]] != t[i]) {
                return false;
            }
        }
        
        return true;
    }
};