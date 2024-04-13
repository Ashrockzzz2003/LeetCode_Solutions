class Solution {
public:
    int largestAreaHistogramRectangle(vector<int>& heights) {
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
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = matrix.size(), m = matrix[0].size();
        vector<int> histogram_height(m, 0);

        int max_area = 0;

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    histogram_height[j]++;
                } else {
                    histogram_height[j] = 0;
                }
            }

            max_area = max(max_area, largestAreaHistogramRectangle(histogram_height));
        }

        return max_area;
    }
};