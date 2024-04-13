class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int max_area = 0;
        stack<int> incOrder;

        for(int i = 0; i <= n; i++) {
            while (!incOrder.empty() && (i == n || heights[incOrder.top()] >= heights[i])) {
                int height_at_top = heights[incOrder.top()];
                incOrder.pop();
                int the_width = incOrder.empty() ? i : i - incOrder.top() - 1;

                max_area = max(max_area, height_at_top * the_width);
            }

            incOrder.push(i);
        }

        return max_area;

        // stack<int> smallestUntil;

        // vector<int> leftSmallestUntil(n), rightSmallestUntil(n); // indices

        // // pre compute left
        // for(int i = 0; i < n; i++) {
        //     while (!smallestUntil.empty() && heights[smallestUntil.top()] >= heights[i]) {
        //         smallestUntil.pop();
        //     }

        //     if (smallestUntil.empty()) {
        //         leftSmallestUntil[i] = 0;
        //     } else {
        //         leftSmallestUntil[i] = smallestUntil.top() + 1;
        //     }

        //     smallestUntil.push(i);
        // }

        // while(!smallestUntil.empty()) {
        //     smallestUntil.pop();
        // }

        // // pre compute right
        // for(int i = n - 1; i >= 0; i--) {
        //     while (!smallestUntil.empty() && heights[smallestUntil.top()] >= heights[i]) {
        //         smallestUntil.pop();
        //     }

        //     if (smallestUntil.empty()) {
        //         rightSmallestUntil[i] = n - 1;
        //     } else {
        //         rightSmallestUntil[i] = smallestUntil.top() - 1;
        //     }

        //     smallestUntil.push(i);
        // }

        // int max_area = 0;

        // for(int i = 0; i < n; i++) {
        //     max_area = max(max_area, (rightSmallestUntil[i] - leftSmallestUntil[i] + 1)*heights[i]);
        // }

        // return max_area;
        

    }
};