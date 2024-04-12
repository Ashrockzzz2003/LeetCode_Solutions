class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMaxUntil(height.size()), rightMaxUntil(height.size());

        leftMaxUntil[0] = height[0];
        rightMaxUntil[height.size() - 1] = height.back();

        for(int i = 1; i < height.size(); i++) {
            leftMaxUntil[i] = max(height[i], leftMaxUntil[i - 1]);
        }

        for(int i = height.size() - 2; i >= 0; i--) {
            rightMaxUntil[i] = max(height[i], rightMaxUntil[i + 1]);
        }

        int totalTrapped = 0;

        for(int i = 0; i < height.size(); i++) {
            totalTrapped += min(leftMaxUntil[i], rightMaxUntil[i]) - height[i];
        }

        return totalTrapped;
    }
};