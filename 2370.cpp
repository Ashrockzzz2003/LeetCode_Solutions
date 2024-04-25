class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);

        int the_final_answer = 0;

        for(int i = 0; i < s.length(); i++) {
            int _current = s[i] - 'a';
            int _best = 0;
            for(int j = 0; j < 26; j++) {
                if (abs(j - _current) <= k) _best = max(_best, dp[j]);
            }

            dp[_current] = max(dp[_current], _best + 1);
            the_final_answer = max(the_final_answer, dp[_current]);
        }

        return the_final_answer;

    }
};