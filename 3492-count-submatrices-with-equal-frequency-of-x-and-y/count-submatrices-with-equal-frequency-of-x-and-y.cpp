class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>>countX(m, vector<int>(n, 0));
        vector<vector<int>>countY(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                countX[i][j] = (grid[i][j] == 'X');
                countY[i][j] = (grid[i][j] == 'Y');

                if(i- 1 >= 0){
                    countX[i][j] += countX[i - 1][j];
                    countY[i][j] += countY[i - 1][j];
                }
                if(j - 1 >= 0){
                    countX[i][j] += countX[i][j - 1];
                    countY[i][j] += countY[i][j - 1];
                }
                if(j - 1 >= 0 && i - 1 >= 0){
                    countX[i][j] -= countX[i - 1][j - 1];
                    countY[i][j] -= countY[i - 1][j - 1];
                }
                if(countX[i][j] == countY[i][j] && countX[i][j] > 0)
                    count++;
            }
        }
        return count;
    }
};