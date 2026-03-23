class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m - k + 1, vector<int>(n - k + 1));

        for(int i = 0; i <= m - k; i++){
            for(int j = 0; j <= n - k; j++){
                set<int>val;
                
                for(int r = i; r <= i + k - 1; r++){
                    for(int c = j; c <= j + k - 1; c++){
                        val.insert(grid[r][c]);
                    }
                }
                if(val.size() == 1){
                    ans[i][j] = 0;
                    continue;
                }
                int minAbsDiff = INT_MAX;
                auto prev = val.begin();
                auto cur = next(prev);

                while(cur != val.end()){
                    minAbsDiff = min(minAbsDiff, *cur - *prev);
                    prev = cur;
                    cur++;
                }
                ans[i][j] = minAbsDiff;
            }
        }
        return ans;
    }
};