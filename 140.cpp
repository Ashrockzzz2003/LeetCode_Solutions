class Solution {
private:
    void search(int i, string &current_sentence, string &s, unordered_map<string, bool> &i_am_a_word, vector<string>& sentences) {
        // cout << current_sentence << endl;
        if (i >= s.length()) {
            sentences.push_back(current_sentence);
            return;
        }

        // i + 10 here as max length of a word is atmost 10 as per constraints
        for(int j = i + 1; j <= i + 10 && j <= s.length(); j++) {
            string word = s.substr(i, j - i);
            if (i_am_a_word[word] == true) {
                if (current_sentence.length() == 0) current_sentence = word;
                else current_sentence += " " + word;

                search(j, current_sentence, s, i_am_a_word, sentences);

                int c = 0;
                while(c < word.length()) {
                    c++;
                    current_sentence.pop_back();
                }
                if (current_sentence.length() > 0) current_sentence.pop_back();
            }
        }


    }
public:
    vector<string> wordBreak(string s, vector<string>& word_dict) {
        vector<string> sentences;
        unordered_map<string, bool> i_am_a_word;
        for(string word: word_dict) {
            i_am_a_word[word] = true;
        }

        string current_sentence = "";
        search(0, current_sentence, s, i_am_a_word, sentences);
        return sentences;
    }
};