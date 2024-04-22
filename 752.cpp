class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        unordered_set<string> dead_end_set(deadends.begin(), deadends.end());
        
        // we're already in deadend
        if (dead_end_set.count("0000") > 0) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({"0000", -1});

        // unordered_map<string, bool> visited;
        // visited["0000"] = true;

        unordered_set<string> visited;
        visited.insert("0000");

        while (!q.empty()) {
            pair<string, int> current_comb = q.front();
            q.pop();

            string current_combination = current_comb.first;
            int current_moves = current_comb.second;

            if (current_combination == target) {
                return current_moves + 1;
            }

            for(int i = 0; i < 4; i++) {
                for(int d : {-1, 1}) {
                    int new_digit = (current_combination[i] - '0' + d + 10) % 10;
                    string new_combination = current_combination;
                    new_combination[i] = '0' + new_digit;

                    if (visited.find(new_combination) == visited.end() && dead_end_set.find(new_combination) == dead_end_set.end()) {
                        visited.insert(new_combination);
                        q.push({new_combination, current_moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};