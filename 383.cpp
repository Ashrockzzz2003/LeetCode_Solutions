class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26);

        for(char i : magazine){
            count[i-'a'] += 1;
        }
        
        for(char i : ransomNote){
            count[i-'a'] -= 1;
            if(count[i-'a'] < 0)
                return false;
        }
        
        return true;
    }
};
