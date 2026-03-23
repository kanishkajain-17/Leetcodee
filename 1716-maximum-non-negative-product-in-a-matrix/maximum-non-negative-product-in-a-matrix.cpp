class Solution {
public:
    typedef long long ll;
    int M = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll, ll>>>dp(m, vector<pair<ll, ll>>(n));
        dp[0][0] = {grid[0][0], grid[0][0]};

        //filling first row
        for(int j = 1; j < n; j++){
            dp[0][j].first = grid[0][j] * dp[0][j - 1].first; //maxVal
            dp[0][j].second = grid[0][j] * dp[0][j - 1].second; //minVal
        }
        //filling first col
        for(int i = 1; i < m; i++){
            dp[i][0].first = grid[i][0] * dp[i - 1][0].first; //maxVal
            dp[i][0].second = grid[i][0] * dp[i - 1][0].second; //minVal
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                ll upMax = dp[i - 1][j].first;
                ll upMin = dp[i - 1][j].second;

                ll leftMax = dp[i][j - 1].first;
                ll leftMin = dp[i][j - 1].second;

                dp[i][j].first = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                dp[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});

            }
        }  
        auto[maxProd, minProd] = dp[m - 1][n - 1];
        if(maxProd < 0)
            return -1;
        return maxProd % M;;  
    }
};