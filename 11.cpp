class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r) {
            max_area = max(max_area, min(height[l], height[r])*(r-l));

            if(height[l] < height[r]) {
                l += 1;
            }
            else {
                r -= 1;
            }
        }

        return max_area;
    }
};
