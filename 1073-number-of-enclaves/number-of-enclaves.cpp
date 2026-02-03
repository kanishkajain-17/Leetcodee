class Solution {
public:
    int m, n;
    void DFS(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0; // paani bana rahe hai phir uss path ko
        DFS(grid, i + 1, j);
        DFS(grid, i, j - 1);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        //boundary par agar 1 hai mtlb vaha se path haii aage ke liye 
        //toh uss cell par DFS lagao or uske charo taraf explore karlo ke vaha se kaha 
        //kaha path par aur ja sakte hai 
        for(int row = 0; row < m; row++){
            //first column
            if(grid[row][0] == 1)
                DFS(grid, row, 0);

            //last column
            if(grid[row][n - 1] == 1)
                DFS(grid, row, n - 1);
        }

        for(int col = 0; col < n; col++){
            //first row
            if(grid[0][col] == 1)
                DFS(grid, 0, col);

            //last row
            if(grid[m - 1][col] == 1)
                DFS(grid, m - 1, col);
        }

        //traversing to count enclosed 1;
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};