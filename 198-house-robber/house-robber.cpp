class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 2; i <= n; i++) {

            int steal = prev2 + nums[i - 1];
            int skip = prev;

            int cur = max(steal, skip);

            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};