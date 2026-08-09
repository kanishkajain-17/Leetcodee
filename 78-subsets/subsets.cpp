class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int n, int i, vector<int> temp) {

        if(i >= n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, n, i + 1, temp);
        temp.pop_back();
        solve(nums, n, i + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums, n, 0, temp);
        return ans;
    }
};