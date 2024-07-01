class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }

        for(int index = 0; index < arr.size() - 2; index++) {
            if (arr[index] % 2 != 0 && arr[index + 1] % 2 != 0 && arr[index + 2] % 2 != 0) {
                return true;
            }
        }

        return false;
    }
};