class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zeros ++;
               // j = i;
            }
            else {
                swap(nums[j], nums[i]);
                j ++;
            }
                
            
            
        }
    }
};