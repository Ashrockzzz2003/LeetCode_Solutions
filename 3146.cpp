class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> index_diff(26, 0);
        
        int permutation_difference = 0;
        
        for(int i = 0; i < s.length(); i++) {
            index_diff[s[i] - 'a'] = i;
        }
        
        for(int j = 0; j < t.length(); j++) {
            permutation_difference += abs(j - index_diff[t[j] - 'a']);
        }
        
        return permutation_difference;
    }
};