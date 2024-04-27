class Solution {
public:
    // bottom up
    int findRotateSteps(string ring, string key) {
        int ring_length = ring.length();
        int key_length = key.length();
        vector<vector<int>> dp(ring_length, vector<int>(key_length + 1, INT_MAX));

        for(int i = 0; i < ring_length; i++) dp[i][key_length] = 0;

        for(int key_index = key_length - 1; key_index > -1; key_index--) {
            for(int ring_index = 0; ring_index < ring_length; ring_index++) {
                for(int k = 0; k < ring_length; k++) {
                    if (ring[k] == key[key_index]) {
                        dp[ring_index][key_index] = min(dp[ring_index][key_index], noOfSteps(ring_index, k, ring_length) + 1 + dp[k][key_index + 1]);
                    }
                }
            }
        }

        // return tryPath(0, 0, ring, key, INT_MAX, dp);

        return dp[0][0];
    }

    int noOfSteps(int current_index, int next_index, int ring_length) {
        return min(abs(current_index - next_index), ring_length - abs(current_index - next_index));
    }

    // Top down with dp
    // int tryPath(int current_ring_index, int key_index, string ring, string key, int min_steps, unordered_map<int, unordered_map<int, int>>& dp) {
    //     if (dp[current_ring_index][key_index]) return dp[current_ring_index][key_index];

    //     if (key_index == key.length()) return 0;

    //     for(int i = 0; i < ring.length(); i++) {
    //         if (ring[i] == key[key_index]) {
    //             min_steps = min(min_steps, noOfSteps(current_ring_index, i, ring.length()) + 1 + tryPath(i, key_index + 1, ring, key, INT_MAX, dp));
    //             dp[current_ring_index][key_index] = min_steps;
    //         }
    //     }

    //     return min_steps;
    // }

    // Top Down
    // int tryPath(int current_ring_index, int key_index, string ring, string key, int min_steps) {
    //     if (key_index == key.length()) return 0;

    //     for(int i = 0; i < ring.length(); i++) {
    //         if (ring[i] == key[key_index]) {
    //             min_steps = min(min_steps, noOfSteps(current_ring_index, i, ring.length()) + 1 + tryPath(i, key_index + 1, ring, key, INT_MAX));
    //         }
    //     }

    //     return min_steps;
    // }
};