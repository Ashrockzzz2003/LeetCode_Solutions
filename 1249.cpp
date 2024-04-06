class Solution {
public:
    string minRemoveToMakeValid(string s) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        stack<long long> st;

        for(long long i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    s[i] = '-';
                } else {
                    st.pop(); // Valid close.
                }
            }
        }

        while (!st.empty()) {
            s[st.top()] = '-';
            st.pop();
        }

        string final_string = "";

        for(long long i = 0; i < s.length(); i++) {
            if(s[i] != '-') final_string.push_back(s[i]);
        }

        return final_string;
    }
};