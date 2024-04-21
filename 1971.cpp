class Solution {
public:
    // bool dfs(int source, int destination, int n, vector<vector<int>>& neighbours, vector<bool>& visited) {
    //     if (source == destination) {
    //         return true;
    //     }

    //     visited[source] = true;

    //     for(int neighbour : neighbours[source]) {
    //         if (visited[neighbour] == false && dfs(neighbour, destination, n, neighbours, visited) == true) return true;
    //     }

    //     return false;
    // }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (source == destination) return true;

        vector<vector<int>> neighbours(n);
        for(vector<int>& edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        stack<int> the_dfs;
        the_dfs.push(source);

        while (!the_dfs.empty()) {
            int next_node = the_dfs.top();
            the_dfs.pop();

            if (next_node == destination) return true;

            visited[next_node] = true;

            for(int neighbour : neighbours[next_node]) {
                if (neighbour == destination) return true;
                if (visited[neighbour] == false) the_dfs.push(neighbour);
            }
        }

        return false;
    }
};