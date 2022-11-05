class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        string x = to_string(n);
        for(int i = 0; i < x.length(); i++){
            product *= (x[i] - 48);
            sum += (x[i] - 48);
        }

        return product - sum;
    }
};
