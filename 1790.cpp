class Solution {
public:
    bool possible(string s1, string s2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }

        return true;
    }
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length()){
            return false;
        }


        if(possible(s1, s2)){
            int count = 0;
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] != s2[i]){
                    count++;
                }
            }
            return (count == 2) || (count == 0);
        }
        else{
            return false;
        }
    }
};
