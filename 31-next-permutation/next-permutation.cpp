class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_idx = -1;
        for (int i = n - 1; i > 0; i -= 1) {
            if(nums[i - 1] < nums[i]){
                gola_idx = i - 1;
                break;
            }
        }
        int swap_idx = gola_idx;
        if(gola_idx != -1) {
            
            for (int i = n - 1; i >= gola_idx + 1; i-= 1) {
                if(nums[i] > nums[gola_idx]) {
                    swap_idx = i;
                    break;
                }
            } 
            swap(nums[gola_idx], nums[swap_idx]);
        }
        
        reverse(begin(nums) + gola_idx + 1, end(nums));

    }
};