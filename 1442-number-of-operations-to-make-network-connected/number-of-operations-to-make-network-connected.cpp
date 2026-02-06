class Solution {
public:
    //total number of components nikal lenge phir components - 1 kar denge 
    //toh required edge aa jayegi
    //bcz n vertices ke liye (n - 1)edge chaiye hoti hai
    //kike eg - toh agar ek component mai sab ek dusre se connect hai mtlb vo ek edge hui
    //aur ek aur component hai toh aab usse connect karne ke liye ek aur edge chaiye 

    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(i == parent[i])
            return i;
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
             rank[y_parent] ++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < (n - 1))
            return -1; //connections mai edges kam hai actual edges se

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;
        for(auto & vec : connections){
            if(find(vec[0]) != find(vec[1])){
                unionn(vec[0], vec[1]);
                components--;
            }
        }
        return components - 1;
    }
};