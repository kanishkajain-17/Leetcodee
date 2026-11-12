class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1;
        int dec = 1;
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1])
                dec += 1;
            else
                dec = 1;
            
            if(nums[i] < nums[i - 1])
                inc += 1;
            else
                inc = 1;
            maxi = max(maxi, max(inc, dec));
        }
        return maxi;
    }
};