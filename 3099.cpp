class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int digitSum = 0, temp = x;
        
        while (temp > 0) {
            digitSum += temp % 10;
            temp /= 10;
        }
        
        if (x % digitSum == 0) {
            return digitSum;
        } else {
            return -1;
        }
    }
};