class Solution {
private:
    bool isBeautiful(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                if (abs(arr[i] - arr[j]) == k) return false;
            }
        }

        return true;
    }

    void generatePowerSet(vector<int>& nums, int i, vector<int>& buffer, vector<vector<int>>& beautiful_subsets, int k) {
        if (isBeautiful(buffer, k)) beautiful_subsets.push_back(buffer);

        for(int j = i; j < nums.size(); j++) {
            buffer.push_back(nums[j]);
            generatePowerSet(nums, j + 1, buffer, beautiful_subsets, k);
            buffer.pop_back();
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> beautiful_subsets;
        vector<int> buffer;

        sort(nums.begin(), nums.end());

        generatePowerSet(nums, 0, buffer, beautiful_subsets, k);

        // for(auto& x: beautiful_subsets) {
        //     cout << endl;
        //     for(auto& i: x) {
        //         cout << i << " ";
        //     }
        // }

        return beautiful_subsets.size() - 1;
    }
};