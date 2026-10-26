class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    long long findSum(vector<vector<int>>& grid, int r, int c) {

        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return 0;
        
        long long sum = grid[r][c];
        grid[r][c] = 0;
    
            
        for (auto &dir : directions) {
            int x = r + dir[0];
            int y = c + dir[1];

           
            sum += findSum(grid, x, y);
            
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    
                    long long sum = findSum(grid, i, j);
                    if(sum % k == 0)
                        count += 1;
                }
            }
        }
        return count;
    }
};