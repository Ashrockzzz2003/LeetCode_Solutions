class Solution {
public:
    int wealth(vector<int>& arr) {
        int total_wealth = 0;
        for(int i = 0; i < arr.size(); i++){
            total_wealth += arr[i];
        }
        return total_wealth;
    }

    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for(int i = 0; i < accounts.size(); i++){
            if(wealth(accounts[i]) > max_wealth){
                max_wealth = wealth(accounts[i]);
            }
        }
        return max_wealth;
    }
};
