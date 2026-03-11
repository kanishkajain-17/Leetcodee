class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();
        vector<int>ans;
        int x = n / 3;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        for(auto & it : mp){
            if(it.second > x)
                ans.push_back(it.first);
        }
        return ans;

    }
};