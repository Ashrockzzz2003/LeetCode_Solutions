class Solution {
public:
    int eval(int x, int y, char c) {
        switch (c) {
            case '*':
                return x * y;
            case '+':
                return x + y;
            case '-':
                return x - y;
            default:
                return 0;
        }
    }

    vector<int> computeWays(string& expression, vector<vector<vector<int>>> dp, int i, int j) {
        if (dp[i][j].size() != 0) return dp[i][j];

        vector<int> no_of_ways;
        bool is_number = true;

        for(int k = i; k <= j; k++) {
            if (!isdigit(expression[k])) {
                is_number = false;

                vector<int> left = computeWays(expression, dp, i, k - 1);
                vector<int> right = computeWays(expression, dp, k + 1, j);

                for(auto l : left) {
                    for(auto r : right) {
                        no_of_ways.push_back(eval(l, r, expression[k]));
                    }
                }
            }
        }

        if (is_number) no_of_ways.push_back(stoi(expression.substr(i, j + 1)));

        dp[i][j] = no_of_ways;
        return dp[i][j];
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        return computeWays(expression, dp, 0, n - 1);
    }
};