class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, -1));
        queue<pair<int, int>> que;

        for (int i = 0;i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    que.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!que.empty()) {

            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for (auto &dir : directions) {

                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n) && ans[new_x][new_y] == -1) {

                    ans[new_x][new_y] = ans[x][y] + 1;
                    que.push({new_x, new_y});
                }
            }
        }
        return ans;
    }
};