class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int i = 0;
        while(i < s.size()){
            if(i+2 < s.length() && s[i+2] == '#'){
                string n;
                n += s[i];
                n += s[i+1];
                int x = stoi(n) + 96;
                char j = x;
                result += j;
                i += 3;
            }
            else{
                int x = s[i] + 48;
                char j = x;
                result += j;
                i++;
            }
        }


        return result;
    }
};
