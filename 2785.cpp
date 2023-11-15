class Solution {
public:
    int isVowel(int key) {
        int vowel_list[10] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};

        int left = 0, right = 9;

        while (left <= right) {
            int mid = (left+right) / 2;
            if (vowel_list[mid] == key) {
                return mid;
            } else if (vowel_list[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    
    string sortVowels(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int vowel_list[10] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
        int is_vowel[s.length()];
        vector<int> vowel_count(10, 0);

        for (int i = 0; i < s.length(); i++) {
            is_vowel[i] = isVowel(s[i]);
            if (is_vowel[i] != -1) {
                vowel_count[is_vowel[i]]++;
            }
        }

        int latest_vowel_index = 0;

        for (int i = 0; i < 10; i++) {
            if (vowel_count[i] != 0) {
                latest_vowel_index = i;
                break;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (is_vowel[i] != -1) {
                if (vowel_count[latest_vowel_index] == 0) {
                    for(int k = latest_vowel_index; k < 10; k++) {
                        if (vowel_count[k] != 0) {
                            latest_vowel_index = k;
                            break;
                        }
                    }
                }

                s[i] = vowel_list[latest_vowel_index];
                vowel_count[latest_vowel_index]--;
            }
        }

        return s;
    }
};