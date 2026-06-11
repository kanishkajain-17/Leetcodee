class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;
    ll power(ll base, ll expo) {
        if(expo == 0)
            return 1;
        ll half = power(base, expo / 2);
        ll ans = (half * half) % M;

        if(expo % 2 != 0)
            ans = (ans * base) % M;
        return ans;
    }
    int findDepth(unordered_map<int, vector<int>> &adj, int node, int parent) {
        int depth = 0;
        for (int &ngbr : adj[node]) {
            if(ngbr == parent)
                continue;
            depth = max(depth, findDepth(adj, ngbr, node) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d = findDepth(adj, 1, -1);
        return power(2, d - 1);
    }
};