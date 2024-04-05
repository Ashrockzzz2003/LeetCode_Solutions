class Solution {
public:
    string makeGood(string s) {
        string good_string;

        for(int i = 0; i < s.length(); i++) {
            if (!good_string.empty() && abs(s[i] - good_string.back()) == 32) {
                good_string.pop_back();
            } else {
                good_string.push_back(s[i]);
            }
        }
        
        return good_string;


        // stack based approach.
        // stack<char> good_chars;

        // for (int i = s.length() - 1; i >= 0; i--) {
        //     if (!good_chars.empty() && abs(s[i] - good_chars.top()) == 32) {
        //         good_chars.pop();
        //     } else {
        //         good_chars.push(s[i]);
        //     }
        // }
        
        // string good_string = "";
        // while (!good_chars.empty()) {
        //     good_string += good_chars.top();
        //     good_chars.pop();
        // }


        // return good_string;
    }
};