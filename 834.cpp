class Solution {
private:
    vector<vector<int>> adj_list;
    vector<int> subtree_node_count;
    vector<int> dist_sum;

    void dfs_1(int node, int parent) {
        for(int i = 0; i < adj_list[node].size(); i++) {
            if (adj_list[node][i] != parent) {
                dfs_1(adj_list[node][i], node);
                subtree_node_count[node] += subtree_node_count[adj_list[node][i]];
                dist_sum[node] += dist_sum[adj_list[node][i]] + subtree_node_count[adj_list[node][i]];
            }
        }
    }

    void dfs_2(int node, int parent) {
        for(int i = 0; i < adj_list[node].size(); i++) {
            if (adj_list[node][i] != parent) {
                dist_sum[adj_list[node][i]] = dist_sum[node] - subtree_node_count[adj_list[node][i]] + subtree_node_count.size() - subtree_node_count[adj_list[node][i]];
                dfs_2(adj_list[node][i], node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj_list = vector<vector<int>>(n);
        subtree_node_count = vector<int>(n, 1);
        dist_sum = vector<int>(n, 0);

        for(auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        dfs_1(0, -1);
        dfs_2(0, -1);

        return dist_sum;

    }
};