class Solution {
public:
    string getRankName(int rank) {
        switch (rank) {
            case 1: return "Gold Medal";
            case 2: return "Silver Medal";
            case 3: return "Bronze Medal";
            default: return to_string(rank);
        }
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> rank;

        int n = score.size();
        vector<int> sorted_array = score;

        sort(sorted_array.begin(), sorted_array.end());

        for(int i = n - 1; i >= 0; i--) {
            rank[sorted_array[i]] = n - i;
        }

        vector<string> final_rank;

        for(int i = 0; i < n; i++) {
            final_rank.push_back(getRankName(rank[score[i]]));
        }

        return final_rank;
    }
};