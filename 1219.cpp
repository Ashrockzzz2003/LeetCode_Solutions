class Solution {
private:
    int maximizeGold(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] == 0) {
            return 0;
        }

        int current_gold = grid[i][j];
        grid[i][j] = 0;

        int max_gold = max({
            maximizeGold(grid, i + 1, j, m, n),
            maximizeGold(grid, i, j + 1, m, n),
            maximizeGold(grid, i - 1, j, m, n),
            maximizeGold(grid, i, j - 1, m, n)
        });

        grid[i][j] = current_gold;
        return max_gold + current_gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int m = grid.size();
        int n = grid[0].size();

        int max_gold = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    max_gold = max(max_gold, maximizeGold(grid, i, j, m, n));
                }
            }
        }

        return max_gold;
    }
};