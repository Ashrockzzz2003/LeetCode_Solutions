class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sameParity(n, 0);

        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                sameParity[i] = 1;
            }
        }

        vector<int> prefixSum(n, 0);
        prefixSum[0] = sameParity[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + sameParity[i];
        }


        vector<bool> answer;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];

            if (from == to) {
                answer.push_back(true);
                continue;
            }

            int sum = prefixSum[to - 1];
            if (from > 0) {
                sum -= prefixSum[from - 1];
            }
            answer.push_back(sum == 0);
        }

        return answer;
    }
};
