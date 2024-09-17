class Solution {
public:
    vector<string> split(string s) {
        vector<string> words;
        int i = 0;
        while(i < s.size()) {
            string word = "";
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            words.push_back(word);
            i++;
        }

        return words;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> words_from_s1 = split(s1);
        vector<string> words_from_s2 = split(s2);
        unordered_map<string, int> net_freq;
        
        for(auto &word: words_from_s1) net_freq[word]++;

        for(auto &word: words_from_s2) net_freq[word]++;

        vector<string> uncommon_words;
        for(auto &it: net_freq) {
            if (it.second == 1) uncommon_words.push_back(it.first);
        }

        return uncommon_words;
    }
};