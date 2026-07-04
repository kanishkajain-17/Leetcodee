class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int &ans, vector<int> &visited, int u) {

        visited[u] = true;

        for (auto &P : adj[u]) {

            int v = P.first;
            int d = P.second;

            ans = min(ans, d);

            if(!visited[v]) {
                dfs(adj, ans, visited, v);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int d = r[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }   

        int ans = INT_MAX;
        vector<int> visited(n + 1, false);

        dfs(adj, ans, visited, 1);

        return ans;
    }
};