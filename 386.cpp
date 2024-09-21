class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lex;
        int current = 1;

        for(int i = 0; i < n; i++) {
            lex.push_back(current);

            if (10*current <= n) current *= 10;
            else {
                while (current%10 == 9 || current >= n) current /= 10;
                current++;
            }
        }

        return lex;
    }
};