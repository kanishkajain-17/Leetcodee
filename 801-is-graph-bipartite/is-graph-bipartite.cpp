class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int iniColor, int u) {

        color[u] = iniColor;

        for (int &v : graph[u]) {

            if(color[v] == color[u])
                return false;

            if(color[v] == -1) {

                int newColor = 1 - color[u];

                if(dfs(graph, color, newColor, v) == false)
                     return false;

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        int iniColor = 1;

        for (int i = 0; i < n; i ++)
            if(color[i] == -1){
                 if(dfs(graph, color, iniColor, i) == false)
                       return false;
            }
        return true;
    }
};