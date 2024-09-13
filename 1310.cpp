class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;

        for(auto q : queries) {
            int xor_res = 0;
            for(int k = q[0]; k <= q[1]; k++) {
                xor_res ^= arr[k];
            }

            answer.push_back(xor_res);
        }

        return answer;
    }
};