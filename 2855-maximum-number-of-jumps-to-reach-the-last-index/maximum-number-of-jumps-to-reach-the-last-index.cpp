class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums, int target, vector<int>& dp){

        if(i == n - 1)
            return 0;

        if(dp[i] != INT_MIN)
            return dp[i];

        int ans = INT_MIN;

        for(int j = i + 1; j < n; j++){
            if(abs(nums[i] - nums[j]) <= target){

                int temp = 1 + solve(j, nums, target, dp);
                ans = max(ans, temp);

            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();
        vector<int>dp(n, INT_MIN);

        int ans = solve(0, nums, target, dp);

        return ans < 0 ? -1: ans;
    }
};