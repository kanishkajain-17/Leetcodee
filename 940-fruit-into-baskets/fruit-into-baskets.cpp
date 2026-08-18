class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int ans = 0;

        while (r < n) {
            
            mp[nums[r]] += 1;

            if(mp.size() > 2) {

                mp[nums[l]] -= 1;
                
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                
                l += 1;
            }
            ans = max(ans, r - l + 1);
            r += 1;
        }
        return ans;
    }
};