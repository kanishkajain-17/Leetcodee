class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>temp, int i){
        if(i == nums.size()){
            if(s.find(temp) == s.end()){
                ans.push_back(temp);
                s.insert(temp);
            }
            
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, i + 1);
        temp.pop_back();
        solve(nums, temp, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(begin(nums), end(nums));
        solve(nums, temp, 0);
        return ans;
    }
};