class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1;
        int distance = INT_MAX;
        
        for (int i = 0; i < points.size(); i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int dis = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (dis < distance) {
                    distance = dis;
                    index = i;
                }
            }
        }
        
        return index;
    }
};
