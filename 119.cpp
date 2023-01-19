class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr;
        long long val = 1;

        for(int r = 1; r <= rowIndex+1; r++) {
            arr.push_back(val);
            val = val * (rowIndex + 1 - r) / r;
        }

        return arr;
    }
};
