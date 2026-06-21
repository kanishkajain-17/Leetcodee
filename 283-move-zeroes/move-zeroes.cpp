class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int j = 0;

        for (int i = 0; i < n; i ++) {
            if(nums[i] == 0)
                zeros += 1;
            else{
                nums[j] = nums[i];
                j += 1;
            }
        }
        while (j < n && (zeros--)) {
            nums[j] = 0;
            j += 1;
        }
    }
};