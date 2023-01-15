class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR Logic
        int morattu_single = 0;
        for(int i = 0; i < nums.size(); i++) {
            morattu_single ^= nums[i];
        }

        return morattu_single;
    }
};
