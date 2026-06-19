class Solution {
public:
    typedef pair<int, int> p;
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<p>> adj(n + 1);
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ans(n + 1, INT_MAX);
        
        for (auto & e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }
        
        ans[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(wt > ans[u])
                continue;
                
            for (auto &node : adj[u]) {
                
                int adjNode = node.first;
                int dist = node.second;
                
                if(wt + dist < ans[adjNode]) {
                    ans[adjNode] = wt + dist;
                    pq.push({ans[adjNode], adjNode});
                }
            }
        }
        int minTime = INT_MIN;
        for (int i = 1; i <= n; i++) {
            minTime = max(minTime, ans[i]);
        }
        if(minTime == INT_MAX)
            return -1;
        return minTime;
    }
};