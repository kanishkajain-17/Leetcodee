class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for (int i = 1; i < n; i += 1) {
            if(nums[i - 1] > nums[i])
                c += 1;
        }
        if(nums[n - 1] > nums[0])   
            c += 1;
        return c == 1 || c == 0;
    }
};