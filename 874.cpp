class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacle_set;
        for (auto obstacle : obstacles) {
            obstacle_set.insert({obstacle[0], obstacle[1]});
        }

        int x = 0, y = 0, dir = 0, max_dist = 0;
        vector<int> X = {0, 1, 0, -1}, Y = {1, 0, -1, 0};

        for (auto command : commands) {
            if (command == -1) dir = (dir + 1) % 4;
            else if (command == -2) dir = (dir + 3) % 4;
            else {
                while (command--) {
                    int next_x = x + X[dir];
                    int next_y = y + Y[dir];
                    if (obstacle_set.find({next_x, next_y}) != obstacle_set.end()) break;
                    x = next_x;
                    y = next_y;
                    max_dist = max(max_dist, x * x + y * y);
                }
            }
        }
        return max_dist;
    }
};