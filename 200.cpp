class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        if (!(i >= 0 && i < n && j >= 0 && j < m)) {
            return;
        }

        if (grid[i][j] == '1') {
            grid[i][j] = '*'; // marking as visited

            dfs(i + 1, j, grid, n, m);
            dfs(i, j + 1, grid, n, m);
            dfs(i - 1, j, grid, n, m);
            dfs(i, j - 1, grid, n, m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int num_islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    dfs(i, j, grid, n, m);
                }
            }
        }

        return num_islands;

    }
};