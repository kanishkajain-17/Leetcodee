class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);


        for (auto &i : invocations) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);

            inDegree[v] += 1;
        }

        vector<int> suspicious(n, false);
        queue<int> que;

        que.push(k);
        suspicious[k] = true;

        while (!que.empty()) {

            int cur = que.front();
            que.pop();

            for (auto &it : adj[cur]) {

                inDegree[it] -= 1;
                if(suspicious[it] == false) {

                    suspicious[it] = true;
                    que.push(it);
                }
            }
        }

        vector<int> ans;
        bool cannotRemove = false;
        for (int i = 0; i < n; i ++) {

            if(suspicious[i] == true && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(suspicious[i] == false)
                ans.push_back(i);
        }

        if(cannotRemove == true) {

            vector<int> vec;
            for (int i = 0; i < n; i ++)
                vec.push_back(i);
            return vec;
        }
        return ans;
    }
};