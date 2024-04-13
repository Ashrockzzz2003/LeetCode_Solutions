class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> smallestUntil;

        vector<int> leftSmallestUntil(n), rightSmallestUntil(n); // indices

        // pre compute left
        for(int i = 0; i < n; i++) {
            while (!smallestUntil.empty() && heights[smallestUntil.top()] >= heights[i]) {
                smallestUntil.pop();
            }

            if (smallestUntil.empty()) {
                leftSmallestUntil[i] = 0;
            } else {
                leftSmallestUntil[i] = smallestUntil.top() + 1;
            }

            smallestUntil.push(i);
        }

        while(!smallestUntil.empty()) {
            smallestUntil.pop();
        }

        // pre compute right
        for(int i = n - 1; i >= 0; i--) {
            while (!smallestUntil.empty() && heights[smallestUntil.top()] >= heights[i]) {
                smallestUntil.pop();
            }

            if (smallestUntil.empty()) {
                rightSmallestUntil[i] = n - 1;
            } else {
                rightSmallestUntil[i] = smallestUntil.top() - 1;
            }

            smallestUntil.push(i);
        }

        int max_area = 0;

        for(int i = 0; i < n; i++) {
            max_area = max(max_area, (rightSmallestUntil[i] - leftSmallestUntil[i] + 1)*heights[i]);
        }

        return max_area;
        

    }
};