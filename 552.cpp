class Solution {
private:
    const int MOD_VALUE = 1000000007;

    int countCombinations(int n, int absent_count, int late_count, vector<vector<vector<int>>>& dp) {
        if (late_count >= 3 || absent_count >= 2) return 0;
        if (n == 0) return 1;
        if (dp[n][absent_count][late_count] != -1) return dp[n][absent_count][late_count];

        int combinations = countCombinations(n - 1, absent_count, 0, dp) % MOD_VALUE;
        combinations = (combinations + countCombinations(n - 1, absent_count + 1, 0, dp) % MOD_VALUE) % MOD_VALUE;
        dp[n][absent_count][late_count] = (combinations + countCombinations(n - 1, absent_count, late_count + 1, dp) % MOD_VALUE) % MOD_VALUE;

        return dp[n][absent_count][late_count];
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return countCombinations(n, 0, 0, dp);
    }
};