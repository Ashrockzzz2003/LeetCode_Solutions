class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start = 0;

        for(int end = 0; end < word.length(); end++) {
            if (word[end] == ch) {
                while(start <= end) {
                    swap(word[end], word[start]);
                    start++;
                    end--;
                }

                return word;
            }
        }

        return word;
    }
};