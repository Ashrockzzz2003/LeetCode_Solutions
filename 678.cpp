class Solution {
public:
    bool checkValidString(string s) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int open = 0, close = 0;

        int n = s.length();

        for(int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }

            if (s[n - 1 - i] == ')' || s[n - 1 - i] == '*') {
                close++;
            } else {
                close--;
            }

            if (open < 0 || close < 0) {
                return false;
            }
        }

        return true;
    }
    // topDown Approach with dp.
    // bool areBracketsBalanced(int i, int extraOpen, const string& s, vector<vector<uint32_t>> dp) {
    //     if (i == s.length()) {
    //         return (extraOpen == 0);
    //     }

    //     if (dp[i][extraOpen] != 2) {
    //         return dp[i][extraOpen];
    //     }

    //     bool balanced = false;

    //     if(s[i] == '*') {
    //         balanced = balanced | (areBracketsBalanced(i + 1, extraOpen + 1, s, dp)); // if * was )

    //         if (extraOpen > 0) {
    //             balanced = balanced | (areBracketsBalanced(i + 1, extraOpen - 1, s, dp)); // if * was (
    //         }

    //         balanced = balanced | (areBracketsBalanced(i + 1, extraOpen, s, dp));
    //     } else if (s[i] == '(') {
    //         balanced = balanced | (areBracketsBalanced(i + 1, extraOpen + 1, s, dp));
    //     } else if (extraOpen > 0) {
    //         balanced = balanced | (areBracketsBalanced(i + 1, extraOpen - 1, s, dp));
    //     }

    //     dp[i][extraOpen] = balanced ? 1 : 0;
    //     return dp[i][extraOpen] == 1;
    // }

    // Bottom Up DP
    // bool checkValidString(string s) {
    //     vector<vector<bool>> dp(s.length() + 1, vector<bool> (s.length() + 1, false));
    //     // 2 means not yet cached.
    //     // 1 -> True, 0 -> False

    //     dp[s.length()][0] = true; // ""

    //     for(int i = s.length() - 1; i >= 0; i--) {
    //         for(int extraOpen = 0; extraOpen <= s.length(); extraOpen++) {
    //             if (s[i] == '*') {
    //                 dp[i][extraOpen] = dp[i][extraOpen] | dp[i + 1][extraOpen + 1];

    //                 if (extraOpen > 0) {
    //                     dp[i][extraOpen] = dp[i][extraOpen] | dp[i + 1][extraOpen - 1];
    //                 }

    //                 dp[i][extraOpen] = dp[i][extraOpen] | dp[i + 1][extraOpen];
    //             } else if (s[i] == '(') {
    //                 dp[i][extraOpen] = dp[i][extraOpen] | dp[i + 1][extraOpen + 1];
    //             } else if (extraOpen > 0) {
    //                 dp[i][extraOpen] = dp[i][extraOpen] | dp[i + 1][extraOpen - 1];
    //             }
    //         }
    //     }

    //     return dp[0][0];
    // }
};