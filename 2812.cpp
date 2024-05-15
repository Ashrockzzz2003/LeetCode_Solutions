class Solution {
private:
    vector<vector<int>> search_directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> max_dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    max_dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto& dir : search_directions) {
                int new_r = i + dir[0];
                int new_c = j + dir[1];

                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && max_dist[new_r][new_c] == INT_MAX) {
                    max_dist[new_r][new_c] = max_dist[i][j] + 1;
                    q.push({new_r, new_c});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;

        pq.push({max_dist[0][0], {0, 0}}); // initially we're at (0, 0)

        vector<vector<int>> max_safeness(n, vector<int>(n, -1));
        max_safeness[0][0] = max_dist[0][0];

        while(!pq.empty()) {
            auto [d, position] = pq.top();
            pq.pop();

            int i = position.first, j = position.second;

            if (i == n - 1 && j == n - 1) {
                return d;
            }

            for (auto& dir : search_directions) {
                int new_r = i + dir[0];
                int new_c = j + dir[1];

                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n) {
                    int new_safeness = min(d, max_dist[new_r][new_c]);
                    if (new_safeness > max_safeness[new_r][new_c]) {
                        max_safeness[new_r][new_c] = new_safeness;
                        pq.push({new_safeness, {new_r, new_c}});
                    }
                }
            }
        }

        return -1;
    }
};