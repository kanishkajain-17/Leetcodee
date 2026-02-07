class Solution {
public:
    typedef tuple<int, int, int> T;
    vector<vector<int>>directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<T, vector<T>, greater<T>>pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>>visited(n, vector<bool>(n, false));

        while(!pq.empty()){
            auto P = pq.top();
            int time = get<0>(P);
            int i = get<1>(P);
            int j = get<2>(P);

            pq.pop();

            if(i == n - 1 && j == n - 1)
                return time;

            for(auto & dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && !visited[i_][j_]){
                        visited[i_][j_] = true;
                        int newTime = max(time, grid[i_][j_]);
                        pq.push({newTime, i_, j_});
                }
            }

        }
        return -1;
    }
};