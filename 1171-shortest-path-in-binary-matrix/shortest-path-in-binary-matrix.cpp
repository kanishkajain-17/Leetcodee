class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions {{1, 1}, {1, -1}, {1, 0},{-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0] == 1)
            return -1;
        
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0] = 0;

        while (!pq.empty()) {

            auto temp = pq.top();
            pq.pop();

            int dist = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            
           for (auto &dir : directions) {

                int new_x = x + dir[0];
                int new_y = y + dir[1];
                int d = 1;

                if((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n)) {

                    if(grid[new_x][new_y] == 0 && dist + d < ans[new_x][new_y]) {

                        ans[new_x][new_y] = dist + d;
                        pq.push({dist + d, {new_x, new_y}});
                    }
                    
                }
           }
        }
        if(ans[m - 1][n - 1] == INT_MAX)
            return -1;
        return ans[n - 1][n - 1] + 1;
    }
};