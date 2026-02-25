class Solution {
public:
    bool solve(vector<int>&nums, int x, int i, vector<vector<int>>&dp){
        int n = nums.size();
        if(x == 0)
            return true;
        if(i >= nums.size())
            return x == 0;

        if(dp[i][x] != -1)
            return dp[i][x];
        bool take = false;

        if(x >= nums[i])
            take = solve(nums, x - nums[i], i + 1, dp);
        
        bool not_take = solve(nums, x, i + 1, dp);

        return dp[i][x] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        //begin(nums) → iterator to first element of nums
        // end(nums) → iterator just after last element
        // 0 → initial value of the sum
        // accumulate → adds all elements in the range
        int S = accumulate(begin(nums), end(nums), 0);
        if(S % 2 != 0)
            return false;
        
        int x = S / 2;
        vector<vector<int>>dp(n + 1, vector<int>(x + 1, -1));

        return solve(nums, x, 0, dp);
    }
};