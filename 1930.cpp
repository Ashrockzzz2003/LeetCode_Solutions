class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> done(26, 0);

        int palindrome_count = 0;

        for (int i = 0; i < s.length() - 2; i++) {
            if (done[s[i] - 'a'] == 0) {
                int j = -1;
                for (j = s.length() - 1; j >= 0; j--) {
                    if (s[i] == s[j]) {
                        break;
                    }
                }

                if (j != -1 && j - i >= 2) {
                    vector<int> freq_buffer(26, 0);

                    for (int k = i+1; k < j; k++) {
                        freq_buffer[s[k] - 'a']++;
                    }

                    for (int k = 0; k < freq_buffer.size(); k++) {
                        if(freq_buffer[k] > 0) {
                            palindrome_count++;
                        }
                    }

                    done[s[i] - 'a'] = 1;
                }
            }
        }

        return palindrome_count;
    }
};