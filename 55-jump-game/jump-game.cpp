class Solution {
public:
    int dp[10001];
    bool solve(vector<int>& nums, int n, int idx) {
        if(idx == n - 1)
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        for (int i = 1; i <= nums[idx]; i += 1) { //har ek value ko leke dekh rahe hai
            if(solve(nums, n, i + idx))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
         int n = nums.size();
        // int maxReachable = 0;

        // for (int i = 0; i < n; i += 1) {

        //     if(i > maxReachable) //n - 1 mila he nahi or i out of bound hoagaya
        //         return false;
        //     maxReachable = max(maxReachable, i + nums[i]);
        //     //nums[i] = jump power
        //     //i = current location
        //     //uss index se nums[i] jump karna hai 
            
        // }
        // return true;
        memset(dp, -1, sizeof(dp));
        return solve(nums, n, 0);
    }
};