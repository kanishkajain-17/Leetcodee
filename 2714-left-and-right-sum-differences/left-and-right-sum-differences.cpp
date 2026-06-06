class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int cur = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i += 1) {
           int  leftSum = cur;
            cur += nums[i]; //cummulative sum
           int rightSum = sum - cur;
            ans[i] = abs(rightSum - leftSum);
        }
        return ans;
    }
};