class Solution {
public:
    int digitSum(string s) {
        int digit_sum = 0;
        for(auto digit : s) digit_sum += digit - 48;
        return digit_sum;
    }

    string convert(string s) {
        string number = "";
        for(auto alphabet : s) number += to_string(alphabet - 96);
        return number;
    }

    int getLucky(string s, int k) {
        // Converting the string to it's mapped integer.
        s = convert(s);

        int resulting_sum = 0;

        // Accumulate sum of digits 'k' times.
        for(int i = 0; i < k; i++) {
            resulting_sum = digitSum(s);
            s = to_string(resulting_sum);
        }

        return resulting_sum;
    }
};