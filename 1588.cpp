class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int total_sum = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i; j < arr.size(); j += 2){
                for(int k = i; k <= j; k++){
                    total_sum += arr[k];
                }
            }
        }

        return total_sum;
    }
};
