class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool> &visited, vector<bool> & inRecursion, int u) {

        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : graph[u]) {

            if(!visited[v]) {
                if(dfs(graph, visited, inRecursion, v))
                    return true;
            }
            else{
                if(inRecursion[v] == true)
                    return true;
            }
            
        }
        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int> ans;
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);

        for (int i = 0; i < n; i ++) {
            if(!visited[i])
                dfs(graph, visited, inRecursion, i);
        }
        
        for (int i = 0; i < n; i ++) {
            if(inRecursion[i] == false)
                ans.push_back(i);
        }
        return ans;
    }
};