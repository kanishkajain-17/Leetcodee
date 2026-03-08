class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int pos = 0; //positive
        int neg = 1; //negative
        for(int k = 0; k < n; k++){
            if(nums[k] > 0){
                ans[pos] = nums[k];
                pos += 2;
            }
            else{
                ans[neg] = nums[k];
                neg += 2;
            }
        }
        return ans;
    }
};