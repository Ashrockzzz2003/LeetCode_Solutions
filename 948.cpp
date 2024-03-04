class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0, j = tokens.size() - 1, score = 0;

        sort(tokens.begin(), tokens.end());

        while (i <= j) {
            if (power >= tokens[i]) {
                // Face Up. Try to Maximize score.
                score++;
                power -= tokens[i];
                i++;
            } else if (i < j && score > 0) {
                // Face Down. Because we cannot increase score.
                score--;
                power += tokens[j];
                j--;
            } else {
                // Ran out of options.
                break;
            }
        }

        return score;
    }
};