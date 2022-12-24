class Solution {
public:
    int titleToNumber(string column_title) {
        int column_number = 0;
        for(auto& letter : column_title) {
            column_number *= 26;
            column_number += letter - 'A' + 1;
        }
        return column_number;
    }
};
