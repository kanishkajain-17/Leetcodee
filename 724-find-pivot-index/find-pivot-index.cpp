class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixL(n);
        vector<int> prefixR(n);

        prefixL[0] = nums[0];
        prefixR[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefixL[i] = nums[i] + prefixL[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            prefixR[i] = nums[i] + prefixR[i + 1];
        }

        for (int i = 0; i < n; i++) {
           
           int leftSum = (i == 0) ? 0 : prefixL[i - 1];
           int rightSum = (i == n - 1) ? 0 : prefixR[i + 1];

           if(leftSum == rightSum)
                return i;
        }
        return -1;
    }
};