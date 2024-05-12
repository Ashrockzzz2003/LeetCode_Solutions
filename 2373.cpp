class Solution {
private:
    int largest_from_sub_matrix(vector<vector<int>>& grid, int row_index, int col_index) {
        int largest_val = 0;

        for(int i = row_index; i < row_index + 3; i++) {
            for(int j = col_index; j < col_index + 3; j++) {
                largest_val = max(largest_val, grid[i][j]);
            }
        }

        return largest_val;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> max_pool_matrix(n - 2, vector<int>(n - 2, 0)); // (n - 2)* (n - 2)

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                max_pool_matrix[i][j] = largest_from_sub_matrix(grid, i, j);
            }
        }

        return max_pool_matrix;
    }
};