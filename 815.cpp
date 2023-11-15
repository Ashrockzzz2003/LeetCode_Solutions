class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        if (source == target) {
            return 0;
        }
        
        unordered_map<int, vector<int>> busStopToBus;

        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                busStopToBus[routes[i][j]].push_back(i);
            }
        }

        vector<int> visited_stop(routes.size(), 0);
        queue<int> bfs_q;

        bfs_q.push(source);

        int min_buses = 0;

        while (!bfs_q.empty()) {
            int num_stops = bfs_q.size();
            while(num_stops--){
                int current_stop = bfs_q.front(); 
                bfs_q.pop();

                if (current_stop == target) {
                    return min_buses;
                }

                for(int i = 0; i < busStopToBus[current_stop].size(); i++){
                    if (visited_stop[busStopToBus[current_stop][i]]) {
                        continue;
                    };

                    visited_stop[busStopToBus[current_stop][i]] = 1;

                    for(int j = 0; j < routes[busStopToBus[current_stop][i]].size(); j++){
                        bfs_q.push(routes[busStopToBus[current_stop][i]][j]);
                    }

                }
            }
            min_buses++;
        }

        return -1;
    }
};