class Solution {
public:
    //asked by many companies
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                c0++;
            else if(nums[i] == 1)
                c1++;
            else
                c2++;
        }
        int i = 0;
        while(i < n && c0 != 0){
            nums[i] = 0;
            c0--;
            i++;
        }
        while(i < n && c1 != 0){
            nums[i] = 1;
            c1--;
            i++;
        }
        while(i < n && c2 != 0){
            nums[i] = 2;
            c2--;
            i++;
        }
    }
};