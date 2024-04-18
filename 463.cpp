class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int perimeter = 0;

        int row = grid.size();
        int col = grid[0].size();


        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    if (i > 0 && grid[i-1][j] == 1) {
                        // above adjacent already counted
                        perimeter -= 2;
                    }

                    if (j > 0 && grid[i][j - 1] == 1) {
                        // left adjacent already counted
                        perimeter -= 2;
                    }

                }
            }
        }


        return perimeter;
    }
};