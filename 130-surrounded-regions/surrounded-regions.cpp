class Solution {
public:
    int m, n;
    void DFS(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'X'  || grid[i][j] == '#')
            return;
        grid[i][j] = '#'; // paani bana rahe hai phir uss path ko
        DFS(grid, i + 1, j);
        DFS(grid, i, j - 1);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);

    }

    void solve(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int row = 0; row < m; row++){
            //first column
            if(grid[row][0] == 'O'){
                DFS(grid, row, 0);
            }
                
            //last column
            if(grid[row][n - 1] == 'O'){
                DFS(grid, row, n - 1);
            }
                
        }

        for(int col = 0; col < n; col++){
            //first row
            if(grid[0][col] == 'O'){
                DFS(grid, 0, col);
            }
                

            //last row
            if(grid[m - 1][col] == 'O'){
                 DFS(grid, m - 1, col);          
            }                
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '#')
                    grid[i][j] = 'O';
                else if(grid[i][j] == 'O')
                    grid[i][j] = 'X';
            }
        }
    }
};