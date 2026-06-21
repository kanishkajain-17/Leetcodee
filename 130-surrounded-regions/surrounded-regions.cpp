class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    void dfs(vector<vector<char>>& board, int i, int j) {

        board[i][j] = '#';

        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if((new_i >= 0 && new_i < m) && (new_j >= 0 && new_j < n) && board[new_i][new_j] == 'O')
                dfs(board, new_i, new_j);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < n; i ++) {

            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[m - 1][i] == 'O')
                dfs(board, m - 1, i);
        }

        for (int j = 0; j < m; j ++) {

            if(board[j][0] == 'O')
                dfs(board, j, 0);
            if(board[j][n - 1] == 'O')
                dfs(board, j, n - 1);
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};