class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        double power = log10(n) / log10(3);
        if(power == (int) power) {
            return true;
        }
        return false;
    }
};
