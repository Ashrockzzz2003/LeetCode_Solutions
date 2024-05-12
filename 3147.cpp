class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n + k, INT_MIN);
        
        int max_energy = INT_MIN;
        
        for(int i = n - 1; i >= 0; i--) {
            if (i + k >= n) {
                dp[i] = energy[i];
            } else {
                dp[i] = dp[i + k] + energy[i];
            }
            
            max_energy = max(max_energy, dp[i]);
        }
        
        return max_energy;
        
    }
};
