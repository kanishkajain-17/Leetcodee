class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int u) {

        if(visited[u] == true)
             return;

        visited[u] = true;

        for (int i = 0; i < isConnected.size(); i++) {
            
            if(!visited[i] && isConnected[u][i] == 1)
                dfs(isConnected, visited, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if(!visited[i]){
                dfs(isConnected, visited, i);
                     count += 1;
            }
        }
        return count;
    }
};