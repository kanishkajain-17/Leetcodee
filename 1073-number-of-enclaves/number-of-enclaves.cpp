class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& board, int i, int j) {

        board[i][j] = -1;

        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if((new_i >= 0 && new_i < m) && (new_j >= 0 && new_j < n) && board[new_i][new_j] == 1)
                dfs(board, new_i, new_j);
        }
    }

    int numEnclaves(vector<vector<int>>& board) {

        m = board.size();
        n = board[0].size();
        int count = 0;

        for (int i = 0; i < n; i ++) {

            if(board[0][i] == 1)
                dfs(board, 0, i);
            if(board[m - 1][i] == 1)
                dfs(board, m - 1, i);
        }

        for (int j = 0; j < m; j ++) {

            if(board[j][0] == 1)
                dfs(board, j, 0);
            if(board[j][n - 1] == 1)
                dfs(board, j, n - 1);
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if(board[i][j] == 1)
                    count += 1;
                    
            }
        }
        return count;
    }
};