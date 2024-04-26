class Solution {
public:
    int exploreAndFind(int row, int column, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row == grid.size() - 1) return grid[row][column];
        if (dp[row][column] != -1) return dp[row][column];

        int min_sum = INT_MAX;
        for(int next_column = 0; next_column < grid[0].size(); next_column++) {
            if (next_column != column) min_sum = min(min_sum, exploreAndFind(row + 1, next_column, grid, dp));
        }

        dp[row][column] = grid[row][column] + min_sum;
        return dp[row][column];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        int min_sum = INT_MAX;

        for(int column = 0; column < grid[0].size(); column++) {
            min_sum = min(min_sum, exploreAndFind(0, column, grid, dp));
        }

        return min_sum;
    }
};