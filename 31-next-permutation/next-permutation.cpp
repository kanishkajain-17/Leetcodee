class Solution {
public:
    //asked by many companies
    void nextPermutation(vector<int>& nums) {
        int n  = nums.size();
        int gola_index = -1;
        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                gola_index = i - 1;
                break;
            }
        }
        if(gola_index != -1){
            int swap_index = 0;
            for(int j = n - 1; j >= gola_index + 1; j--){
                if(nums[j] > nums[gola_index]){
                    swap_index = j;
                    break;
                }
            }
            swap(nums[swap_index], nums[gola_index]);
        }
       

        reverse(begin(nums) + gola_index + 1, end(nums));
    }
};