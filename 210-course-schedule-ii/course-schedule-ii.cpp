class Solution {
public:
    bool dfs(vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited, int u, vector<bool> & inRecursion) {

        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {
            if(visited[v] == true){
                if(inRecursion[v] == true)
                    return true;
            }
            else{
                if(dfs(adj, st, visited, v, inRecursion))
                    return true;
            }
        }
        inRecursion[u] = false;
        st.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> ans;

        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }

        stack<int> st;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (int i = 0; i < numCourses; i ++) {
            if(!visited[i]) 
               if(dfs(adj, st, visited, i, inRecursion))
                    return {};
        }

        
        while (!st.empty()) {
           // cout<<st.top()<<" ";
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

};