class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = (int) pow(2, n - 1) * m;

        for(int j = 1; j < n; j++) {
            int curr_score = 0;

            for(int i = 0; i < m; i++) {
                curr_score += ((grid[i][0] == grid[i][j]) ? 1 : 0);
            }

            res += max(curr_score, m - curr_score) * ((int) pow(2, n - 1 - j));
        }
        return res;
    }
};