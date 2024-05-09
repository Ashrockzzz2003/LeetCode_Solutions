class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        long long max_happiness_sum = 0;
        for(long long i = n - 1; i >= 0 && k > 0; i--) {
            max_happiness_sum += (happiness[i] - (n - 1 - i) > 0 ? happiness[i] - (n - 1 - i) : 0);
            k--;
        }

        return max_happiness_sum;

    }
};