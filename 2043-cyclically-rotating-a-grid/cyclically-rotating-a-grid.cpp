class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        
        for(int layer = 0; layer < layers; layer++){
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;

            vector<int>nums;

            //left to right
            for(int i = left; i <= right; i++)
                nums.push_back(grid[top][i]);
            
            //top to bottom
            for(int i = top + 1; i <= bottom - 1; i++)
                nums.push_back(grid[i][right]);
            
            //right to left
            for(int i = right; i >= left; i--)
                nums.push_back(grid[bottom][i]);
            
            //bottom to up
            for(int i = bottom - 1; i >= top + 1; i--)
                nums.push_back(grid[i][left]);

            int len = nums.size();
            int normal_k = k % len;

            rotate(begin(nums), begin(nums) + normal_k, end(nums));

            int idx = 0;

            for(int i = left; i <= right; i++)
                grid[top][i] = nums[idx++];
            
            for(int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = nums[idx++];
            
            for(int i = right; i >= left; i--)
                grid[bottom][i] = nums[idx++];
            
            for(int i = bottom - 1; i >= top + 1; i--)
                grid[i][left]  = nums[idx++];
        }
        return grid;
    }
};