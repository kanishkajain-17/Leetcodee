class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;

        for (int i = 0; i < n; i ++) {

            int count = 0;
            while (i < n && nums[i] == 1) {
                count += 1;
                i += 1;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};