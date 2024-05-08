class Solution {
public:
    // string getRankName(int rank) {
    //     switch (rank) {
    //         case 1: return "Gold Medal";
    //         case 2: return "Silver Medal";
    //         case 3: return "Bronze Medal";
    //         default: return to_string(rank);
    //     }
    // }

    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> heap;
        for(int i = 0; i < n; i++) {
            heap.push({score[i], i});
        }

        vector<string> final_ranks(n);

        int curr_rank = 1;

        while (!heap.empty()) {
            int original_index = heap.top().second;
            heap.pop();
            if (curr_rank == 1) final_ranks[original_index] = "Gold Medal";
            else if (curr_rank == 2) final_ranks[original_index] = "Silver Medal";
            else if (curr_rank == 3) final_ranks[original_index] = "Bronze Medal";
            else final_ranks[original_index] = to_string(curr_rank);
            
            curr_rank++;
        }

        return final_ranks;
        // unordered_map<int, int> rank;

        // int n = score.size();
        // vector<int> sorted_array = score;

        // sort(sorted_array.begin(), sorted_array.end());

        // for(int i = n - 1; i >= 0; i--) {
        //     rank[sorted_array[i]] = n - i;
        // }

        // vector<string> final_rank;

        // for(int i = 0; i < n; i++) {
        //     final_rank.push_back(getRankName(rank[score[i]]));
        // }

        // return final_rank;
    }
};