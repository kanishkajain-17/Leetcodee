class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        sort(begin(nums), end(nums));
        
        int count = 1;
        int maxCount = 1;
        for (int i = 1; i < n; i ++) {
            if(i < n && (nums[i] - nums[i - 1] == 1 )) {
                count += 1;
                maxCount = max(count, maxCount);
            }
            else if(nums[i] - nums[i - 1] == 0)
                continue;
            else
             count = 1;

        }
        return maxCount;
    }
};