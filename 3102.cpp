class Solution {
public:
    // int manhattanDistance(vector<vector<int>>& points, int i, int j) {
    //     return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    // }
    
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size(), minDistance = INT_MAX;

        multiset<int> sum, diff;
        for(int i = 0; i < n; i++) {
            sum.insert(points[i][0] + points[i][1]);
            diff.insert(points[i][0] - points[i][1]);
        }

        for(int i = 0; i < n; i++) {
            sum.erase(sum.find(points[i][0] + points[i][1]));
            diff.erase(diff.find(points[i][0] - points[i][1]));

            int maxDistance = max(*sum.rbegin() - *sum.begin(), *diff.rbegin() - *diff.begin());
            minDistance = min(minDistance, maxDistance);

            sum.insert(points[i][0] + points[i][1]);
            diff.insert(points[i][0] - points[i][1]);
        }

        return minDistance;
    }
};