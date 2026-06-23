class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int curSum = 0;   
     
        for (int i = 0; i < n; i ++) {

            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};