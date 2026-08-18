class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int zeroCount = 0;
        while (r < n) {

            if(nums[r] == 0)
                zeroCount += 1;
            
            while (zeroCount > k) {
                if(nums[l] == 0)
                    zeroCount -= 1;
                l += 1;
            } 
            maxLen = max(maxLen, r - l + 1);
            r += 1;
        }
        return maxLen;
    }
};