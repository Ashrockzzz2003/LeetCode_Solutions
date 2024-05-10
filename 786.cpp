class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<double>> pair_fractions;

        int N = arr.size();

        for(int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                pair_fractions.push_back({(double) arr[i] / (double) arr[j], (double) arr[i], (double) arr[j]});
            }
        }

        sort(pair_fractions.begin(), pair_fractions.end());
        return {(int) pair_fractions[k - 1][1], (int) pair_fractions[k - 1][2]};

    }
};