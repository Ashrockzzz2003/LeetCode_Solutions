class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int one_count = 0;

        for (auto c : s) {
            one_count += (c == '1');
        }

        int zero_count = s.length() - one_count;
        one_count--;

        string max_odd_binary_string = "";


        while (one_count-- > 0) {
            max_odd_binary_string += '1';
        }

        while (zero_count--) {
            max_odd_binary_string += '0';
        }

        max_odd_binary_string += '1';

        return max_odd_binary_string;


    }
};