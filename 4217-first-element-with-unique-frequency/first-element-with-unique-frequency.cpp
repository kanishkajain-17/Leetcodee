class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp, mp1;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        
        for(auto & i : mp)
            mp1[i.second]++;
        
        for(int i = 0; i < n; i++){
            if(mp1[mp[nums[i]]] == 1)
                return nums[i];
        }
        return -1;
    }
};