class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if(n == 1) return {0};

        vector<vector<int>> adjacency_list(n);
        vector<int> degree(n, 0);

        // n - 1 here cos they mentioned it in qn
        for(int i = 0; i < n - 1; i++) {
            adjacency_list[edges[i][0]].push_back(edges[i][1]);
            adjacency_list[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> leaf_queue;
        for(int i = 0; i < n; i++) {
            if (degree[i] == 1) leaf_queue.push(i);
        }

        int remaining_nodes = n;

        while (remaining_nodes > 2) {
            int leaf_count = leaf_queue.size();
            remaining_nodes -= leaf_count;

            for(int i = 0; i < leaf_count; i++) {
                int leaf = leaf_queue.front();
                leaf_queue.pop();
                for(int neighbor : adjacency_list[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leaf_queue.push(neighbor);
                    }
                }
            }
        }


        vector<int> mht;
        while (!leaf_queue.empty()) {
            mht.push_back(leaf_queue.front());
            leaf_queue.pop();
        }

        return mht;

    }
};