class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;
        int windowSum = 0;
        int countZeros = 0;

        while (r < n) {

            windowSum += nums[r];

            while (l < r && (nums[l] == 0 || windowSum > goal)) {
                if(nums[l] == 0)    
                    countZeros += 1;
                else
                    countZeros = 0;
                windowSum -= nums[l];
                l += 1;
            }
            if(windowSum == goal) {
                count += 1 + countZeros;
            }
            r += 1;


        }
        return count;

       
        
    }
};