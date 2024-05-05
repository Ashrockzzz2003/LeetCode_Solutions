class Solution {
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> freq;        
        for(char& c : s) {
            freq[c]++;
        }

        int gcd = freq[s[0]];

        for(auto& x : freq) {
            gcd = __gcd(gcd, x.second);
        }

        return s.length() / gcd;
        
        // xxe
        // x 2 || e 1
        
        // cdef
        // c 1 d 1 e 1 f 1
    }
};