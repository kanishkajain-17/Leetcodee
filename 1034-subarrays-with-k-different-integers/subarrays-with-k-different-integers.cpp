class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int count = 0;

        while (r < n) {

            mp[nums[r]] += 1;

            while (mp.size() > k) {
                mp[nums[l]] -= 1;

                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l += 1;
            }
            
            count += r - l + 1;
            r += 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMost(nums, k) - atMost(nums, k - 1);
    }
};