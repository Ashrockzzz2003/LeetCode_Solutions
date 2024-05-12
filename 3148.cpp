class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int max_score = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                int min_here = INT_MAX;
                if (i != 0) min_here = min(min_here, grid[i - 1][j]);
                if (j != 0) min_here = min(min_here, grid[i][j - 1]);
                max_score = max(max_score, grid[i][j] - min_here);
                grid[i][j] = min(grid[i][j], min_here);
            }
        }

        return max_score;
    }
};
