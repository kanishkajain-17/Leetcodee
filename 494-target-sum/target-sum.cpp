class Solution {
public:
    unordered_map<string, int>mp;
    int solve(vector<int>& nums, int target, int i){
        
        string key = to_string(i) + "-" + to_string(target);
        
        if(i == nums.size())
            return target == 0;
        
        if(mp.count(key))
            return mp[key];

        // int minus = 0;
        // if(target >= nums[i])
            int minus = solve(nums, target - nums[i], i + 1);
        int plus = solve(nums, target + nums[i], i + 1);

        return mp[key] = plus + minus;
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, target, 0);
    }
};