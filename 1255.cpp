class Solution {
private:
    int search(vector<string>& words, int i, unordered_map<char, int>& freq, vector<int>& score) {
        if (i == words.size()) return 0;

        unordered_map<char, int> new_freq = freq;

        // can we take the ith word or not.
        bool can_form = true;

        // score if we can take the word.
        int value = 0;
        for(int j = 0; j < words[i].size() && can_form; j++) {
            new_freq[words[i][j]]--;
            can_form = can_form && (new_freq[words[i][j]] >= 0);
            value += score[words[i][j] - 'a'];
        }

        int max_value = 0;

        // take
        if (can_form) max_value = value + search(words, i + 1, new_freq, score);

        // not take
        max_value = max(max_value, search(words, i + 1, freq, score));

        return max_value;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> freq;
        for(char c : letters) freq[c]++;

        return search(words, 0, freq, score);
    }
};