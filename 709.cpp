class Solution {
public:
    string toLowerCase(string s) {
        for(auto &i: s){
            i = tolower(i);
        }
        return s;
    }
};
