class Solution {
public:
    int solve(int i, int n, vector<int>& nums){
        int prev = nums[i];
        int prevPrev = 0;
        int curr = 0;

        for(int j = i + 1; j <= n; j++){
            int first = prevPrev + nums[j];
            int second = prev;

            curr = max(first, second);

            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
            
        int first = solve(0, n - 2, nums);
        int second = solve(1, n - 1, nums);
        return max(first, second);
    }
};