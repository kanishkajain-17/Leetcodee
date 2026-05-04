class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int> &nums, int n, vector<int>temp, int i){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, n, temp, i + 1);
        temp.pop_back();
        solve(nums, n, temp, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        solve(nums, n, temp, 0);
        return ans;
    }
};