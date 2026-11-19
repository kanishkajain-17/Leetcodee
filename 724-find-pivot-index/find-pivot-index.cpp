class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++)
            totalSum += nums[i];

        int leftSum = 0;
        int rightSum = 0;
        int cumSum = 0; //cummulative sum

        for (int i = 0; i < n; i++) {
            leftSum = cumSum;

            rightSum = totalSum - leftSum - nums[i];

            if(leftSum == rightSum)
                return i;
            
            cumSum += nums[i];
        }
        return -1;
    }
};