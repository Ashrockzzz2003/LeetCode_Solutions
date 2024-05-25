class Solution {
private:
    bool canBuildUpTo(int i, vector<int>& dp, string& s, vector<string>& word_dict) {
        if (i < 0) return true;
        if (dp[i] != -1) return dp[i] == 1;

        for(string word : word_dict) {
            int len = word.length();
            if (i - len + 1 < 0) continue;

            if (s.substr(i - len + 1, len) == word && canBuildUpTo(i - len, dp, s, word_dict)) {
                dp[i] = 1;
                return true;
            }
        }

        dp[i] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& word_dict) {
        vector<int> dp(s.length(), -1);
        return canBuildUpTo(s.length() - 1, dp, s, word_dict);
    }
};