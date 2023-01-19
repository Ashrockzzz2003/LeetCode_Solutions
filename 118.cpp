class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        for(int n = 1; n <= numRows; n++) {
            int val = 1;
            vector<int> temp;

            for(int r = 1; r <= n; r++) {
                temp.push_back(val);
                val = val * (n - r) / r;
            }

            arr.push_back(temp);
        }

        return arr;
    }
};
