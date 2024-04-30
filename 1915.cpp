#define ll long long

class Solution {
public:
    ll wonderfulSubstrings(string word) {
        unordered_map<int, int> count;

        int bitmask = 0;
        count[0] = 1;

        ll final_count = 0;

        for(int i = 0; i < word.length(); i++) {
            bitmask ^= 1 << (word[i] - 'a');
            final_count += count[bitmask];

            // till j from a
            for(int k = 0; k < 10; k++) {
                final_count += count[bitmask ^ (1 << k)];
            }

            count[bitmask]++;
        }

        return final_count;
    }
};