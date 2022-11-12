class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        if(word1.length() < word2.length()){
            int j = 0; // pointer to word2
            for(int i = 0; i < word1.length(); i++){
                merged += word1[i];
                merged += word2[i];
                j++;
            }
            for(int i = j; i < word2.size(); i++){
                merged += word2[i];
            }
        }
        else if(word1.length() > word2.length()){
            int j = 0; // pointer to word1
            for(int i = 0; i < word2.length(); i++){
                merged += word1[i];
                merged += word2[i];
                j++;
            }
            for(int i = j; i < word1.size(); i++){
                merged += word1[i];
            }
        }
        else{
            for(int i = 0; i < word1.length(); i++){
                merged += word1[i];
                merged += word2[i];
            }
        }

        return merged;
    }
};
