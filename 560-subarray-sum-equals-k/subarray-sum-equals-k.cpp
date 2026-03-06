class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        unordered_map<int, int>mp;
        int count = 0;

        mp.insert({0, 1}); //initial sum = 0 (1 time)
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end())
                count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};