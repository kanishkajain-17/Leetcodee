class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                int low = lower_bound(begin(ans), end(ans), nums[i]) - ans.begin();
                ans[low] = nums[i];
            }
        }
        return ans.size();
    }
};