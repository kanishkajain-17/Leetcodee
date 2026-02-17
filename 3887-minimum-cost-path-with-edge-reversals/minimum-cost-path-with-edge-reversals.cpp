class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto & e: edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});//distance, node
        vector<int>ans(n, INT_MAX);
        ans[0] = 0;
       
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n - 1)
                return ans[n - 1];
            for(auto & vec : adj[node]){
                int adjNode = vec.first;
                int wt = vec.second;
                if(d + wt < ans[adjNode]){
                    ans[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
            return -1;
    }
};