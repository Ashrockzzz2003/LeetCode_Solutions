class Solution {
public:
    void dfs(vector<int>& farmlandGroup, int i, int j, vector<vector<int>>& land, int n, int m) {
        if (!(i >= 0 && i < n && j >= 0 && j < m) || land[i][j] != 1) {
            return;
        }

        farmlandGroup[0] = min(farmlandGroup[0], i);
        farmlandGroup[1] = min(farmlandGroup[1], j);
        farmlandGroup[2] = max(farmlandGroup[2], i);
        farmlandGroup[3] = max(farmlandGroup[3], j);

        land[i][j] = 2;

        // if (land[i + 1][j] != 1 && land[i][j + 1] != 1 && land[i - 1][j] != 1 && land[i][j - 1] != 1) {
        //     // no neighbors
        //     largestX = max(largestX, i);
        //     largestY = max(largestY, j);
        //     return;
        // }

        if (i + 1 >= 0 && i + 1 < n && land[i + 1][j] == 1) {
            dfs(farmlandGroup, i + 1, j, land, n, m);
        }

        if (j + 1 >= 0 && j + 1 < m && land[i][j + 1] == 1) {
            dfs(farmlandGroup, i, j + 1, land, n, m);
        }

        if (i - 1 >= 0 && i - 1 < n && land[i - 1][j] == 1) {
            dfs(farmlandGroup, i - 1, j, land, n, m);
        }

        if (j - 1 >= 0 && j - 1 < m && land[i][j - 1] == 1) {
            dfs(farmlandGroup, i, j - 1, land, n, m);
        }

        return;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = land.size(), m = land[0].size();

        vector<vector<int>> farmLandGroups;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    vector<int> farmlandGroup{301, 301, -1, -1};
                    dfs(farmlandGroup, i, j, land, n, m);
                    if (farmlandGroup[0] != 301 && farmlandGroup[1] != 301 && farmlandGroup[2] != -1 && farmlandGroup[3] != -1) {
                        farmLandGroups.push_back(farmlandGroup);
                    }
                }
            }
        }

        return farmLandGroups;
    }
};