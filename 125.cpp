class Solution {
public:
    string format(string s) {
        string x;
        for(int i = 0; i < s.length(); i++) {
            if(isalnum(s[i])) {
                x += tolower(s[i]);
            }
        }

        return x;
    }
    bool isPalindrome(string s) {
        s = this->format(s);
        for(int i = 0; i < s.length()/2; i++) {
            if(s[i] != s[s.length()-1-i]) {
                return false;
            }
        }

        return true;
    }
};
