class Solution {
public:
    int solve(int amount, vector<int>& coins, int i,  vector<vector<int>>& dp, int & count){
        if(i == coins.size()){
           if(amount == 0){
                 count++;
                 return count;
           }
           else
            return 0;
        }

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = 0;
        if(amount >= coins[i])
            take = solve(amount - coins[i], coins, i, dp, count);
        int not_take = solve(amount, coins, i + 1, dp, count);

        return dp[i][amount] = take + not_take;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));
        int count = 0;
         return solve(amount, coins, 0, dp, count);
    }
};