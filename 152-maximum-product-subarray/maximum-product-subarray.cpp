class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxNum = INT_MIN;
        int num = 1;

        for (int i = 0; i < n; i ++) {
            num = 1;
            for (int j = i; j < n; j ++) {

                num *= nums[j];
                maxNum = max(maxNum, num);

            }
            
        }
        return maxNum;
    }
};