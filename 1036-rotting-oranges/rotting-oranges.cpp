class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;
        int minutes = 0;
        
        queue<pair<int, int>> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if(grid[i][j] == 1)
                    freshOranges += 1;

                else if(grid[i][j] == 2)
                    que.push({i, j});

            }
        }

        while (!que.empty() && freshOranges != 0) {

            int N = que.size();

            while (N--) {

                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                for (auto &dir : directions) {

                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n) && grid[new_x][new_y] == 1) {

                        que.push({new_x, new_y});
                        grid[new_x][new_y] = 2;
                         freshOranges -= 1;
                    }
                }
            }
           
            minutes += 1;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};