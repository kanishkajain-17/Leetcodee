class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for (int i = 0; i < n; i++)
            mp[nums[i]] ++;
        
        for (auto &m : mp) {
            if(m.second > 1)
                ans.push_back(m.first);
        }
        return ans;
    }
};