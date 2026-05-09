// Bridges in Graph - Tarjan's Algorithm
// Love Babbar Style

class Solution {
public:
    
    void dfs(int node, int parent,
             vector<int> &disc,
             vector<int> &low,
             vector<bool> &visited,
             unordered_map<int, list<int>> &adj,
             vector<vector<int>> &result,
             int &timer) {
        
        visited[node] = true;
        
        disc[node] = low[node] = timer++;
        
        for(auto nbr : adj[node]) {
            
            // ignore parent
            if(nbr == parent)
                continue;
            
            // not visited
            if(!visited[nbr]) {
                
                dfs(nbr, node, disc, low, visited, adj, result, timer);
                
                // update low
                low[node] = min(low[node], low[nbr]);
                
                // check bridge condition
                if(low[nbr] > disc[node]) {
                    result.push_back({node, nbr});
                }
            }
            else {
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, list<int>> adj;
        
        // create adjacency list
        for(auto edge : connections) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> disc(n);
        vector<int> low(n);
        vector<bool> visited(n, false);
        
        vector<vector<int>> result;
        
        int timer = 0;
        
        // dfs for all components
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, -1, disc, low, visited, adj, result, timer);
            }
        }
        
        return result;
    }
};