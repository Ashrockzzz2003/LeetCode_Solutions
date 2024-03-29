class Solution {
public:
    bool isAlienSorted(vector<string>& W, string O) {
        unordered_map<char,int> crypt;
        for (int i = 0; i < O.size(); i++)
            crypt[O[i]] = i;
        for (int i = 1; i < W.size(); i++) {
            string a = W[i-1], b = W[i];
            for (int j = 0; j < a.size(); j++) {
                if (j == b.size())
                    return false;

                char achar = a[j], bchar = b[j];
                if (crypt[achar] < crypt[bchar]) 
                    break;
                if (crypt[achar] > crypt[bchar]) 
                    return false;
            }
        }
        return true;
    }
};
