class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int ans = 0;
        int i = 0, j = 0;

        while (j < n) {

            mp[nums[j]] += 1;

            while (i < j && mp[nums[j]] > k) {
                mp[nums[i]] -= 1;
                i += 1;
            }
            ans = max(ans, j - i + 1);
            j += 1;
        }
        return ans;
    }
};