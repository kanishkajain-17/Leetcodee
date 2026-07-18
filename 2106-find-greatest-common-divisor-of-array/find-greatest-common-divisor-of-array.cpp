class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i ++) {
            small = min(small, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return __gcd(small, maxi);
    }
};