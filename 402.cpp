class Solution {
public:
    string removeKdigits(string num, int k) {
        string smallest_num = "";

        for(int i = 0; i < num.length(); i++) {
            while (smallest_num.length() > 0 && smallest_num.back() > num[i] && k > 0) {
                smallest_num.pop_back();
                k--;
            }

            if (smallest_num.length() > 0 || num[i] != '0') {
                smallest_num.push_back(num[i]);
            }
        }

        while (smallest_num.size() > 0 && k--) {
            smallest_num.pop_back();
        }

        return smallest_num.length() > 0 ? smallest_num : "0";
    }
};