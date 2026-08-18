class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        for (int i = 0; i < 9; i++)
            if(board[row][i] == dig)
                return false;

        for (int i = 0; i < 9; i++)
            if(board[i][col] == dig)
                return false;

        int sr = (row / 3) * 3; //starting row
        int sc = (col / 3) * 3; //starting col

        for (int i = sr; i <= sr + 2; i++) {
            for (int j = sc; j <= sc + 2; j++) {
                if(board[i][j] == dig)
                    return false;
            }
        } 
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col) {

        if(row == 9)
            return true;
        
        int newRow = row;
        int newCol = col + 1;

        if(newCol == 9) {
            newRow = row + 1;
            newCol = 0;
        }

        if(board[row][col] != '.')
            return solve(board, newRow, newCol);

        for (char dig = '1'; dig <= '9'; dig += 1) {

            if(isSafe(board, row, col, dig)) {

                board[row][col] = dig;

                if(solve(board, newRow, newCol))
                    return true;
                
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};