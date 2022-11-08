class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(auto v: nums){
            if(v == 0){
                return 0;
            }
            if(v < 0){
                sign *= -1;
            }
        }

        return sign;
    }
};
