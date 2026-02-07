class Solution {
public:
vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i] == i)
            return parent[i];
        return parent[i] = find(parent[i]);
    }

    void unionn(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
            return;
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;

        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;

        else{
             parent[x_parent] = y_parent;
             rank[y_parent]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int>mapMailNode;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end())
                    mapMailNode[mail] = i;

                else
                    unionn(i, mapMailNode[mail]);
            }
        }

        vector<vector<string>>mergeMail(n);
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = find(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i = 0; i < n; i++){
            if(mergeMail[i].size() == 0)//no mail fo that
                continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};