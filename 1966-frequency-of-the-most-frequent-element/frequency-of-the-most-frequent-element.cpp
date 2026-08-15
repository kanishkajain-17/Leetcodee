class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = 0;
        long curSum = 0;
        int n = nums.size();
        int l = 0;
        
        for (int r = 0; r < n; r++) {

            long target = nums[r];
            curSum += nums[r];

            if((r - l + 1) * target - curSum > k) {
                curSum -= nums[l];
                l += 1;
            } 
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};