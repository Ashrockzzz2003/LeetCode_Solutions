class Solution {
public:
    int lengthOfLastWord(string s) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int i = s.length() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int last_word_length = 0;

        while (i >= 0 && s[i] != ' ') {
            last_word_length++;
            i--;
        }

        return last_word_length;


    }
};