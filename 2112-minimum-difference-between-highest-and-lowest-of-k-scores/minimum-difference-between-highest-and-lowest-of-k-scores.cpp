class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int minDiff = INT_MAX;
        sort(begin(nums), end(nums));

        for(int i = k - 1; i < n; i++){
            int minEl = nums[i - k + 1];
            int maxEl = nums[i];

            minDiff = min(minDiff, maxEl - minEl);
        }
        return minDiff;
    }
};