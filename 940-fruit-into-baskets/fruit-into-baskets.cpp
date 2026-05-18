class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxNum = 0;
        unordered_map<int, int> mp;

        while (r < n) {

            mp[nums[r]] += 1;

            if(mp.size() > 2) {
                mp[nums[l]] -= 1;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l += 1;
                cout<<l<<" ";
            }

            maxNum = max(maxNum, r - l + 1);
            r += 1;

        }
        return maxNum;
    }
};