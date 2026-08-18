class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n)
            return *max_element(begin(nums), end(nums));


        vector<int> freq(51);

        for (int num : nums)
            freq[num] += 1;
        
        if(k == 1) {

            for (int i = 50; i >= 0; i-= 1) {
                if(freq[i] == 1)
                    return i;
            }
            return -1;
        }
        int ans = -1;

        if(freq[nums[0]] == 1)
            ans = max(ans, nums[0]);
        if(freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;

    }
};