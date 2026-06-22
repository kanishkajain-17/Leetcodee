class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; //sum, freq of that sum
        int n = nums.size();
        int sum = 0;
        int count = 0;
        //mp.insert({0, 1});
        for (int i = 0; i < n; i ++) {

            sum += nums[i];

            if(sum == k)
                count += 1;
                
            if(mp.find(sum - k) != mp.end())
                count += mp[sum - k];
            
            mp[sum]++;
            
        }
        return count;
    }
};