class Solution {
public:
    int maxDepth(string s) {
        int the_max_depth = 0;
        int current_depth = 0;

        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                current_depth++;
                the_max_depth = max(the_max_depth, current_depth);
            } else if (s[i] == ')') {
                current_depth--;
            }
        }

        return the_max_depth;
    }
};