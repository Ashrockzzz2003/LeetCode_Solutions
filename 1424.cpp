class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        if (nums.size() == 1) {
            return nums[0];
        }

        queue<pair<int, int>> bfs_queue;
        bfs_queue.push({0, 0});
        vector<int> finalList;

        while(!bfs_queue.empty()) {
            pair<int, int> p = bfs_queue.front();
            bfs_queue.pop();

            finalList.push_back(nums[p.first][p.second]);

            if (p.second == 0 && p.first + 1 < nums.size()) {
                bfs_queue.push({p.first + 1, p.second});
            }

            if (p.second + 1 < nums[p.first].size()) {
                bfs_queue.push({p.first, p.second + 1});
            }
        }

        return finalList;

        // map<int, vector<int>> diagonalSumMap;

        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = 0; j < nums[i].size(); j++) {
        //         diagonalSumMap[i + j].push_back(nums[i][j]);
        //     }
        // }

        // vector<int> finalList;

        // for(auto v : diagonalSumMap) {
        //     for (int j = v.second.size() - 1; j >= 0; j--) {
        //         finalList.push_back(v.second[j]);
        //     }
        // }

        // return finalList;
    }
};