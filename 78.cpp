class Solution {
private:
    void generatePowerSet(vector<int>& nums, int i, vector<int>& buffer, vector<vector<int>>& power_set) {
        power_set.push_back(buffer);

        for(int j = i; j < nums.size(); j++) {
            buffer.push_back(nums[j]);
            generatePowerSet(nums, j + 1, buffer, power_set);
            buffer.pop_back();
        }

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> power_set;
        vector<int> buffer;
        generatePowerSet(nums, 0, buffer, power_set);
        return power_set;
    }
};