class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int mid) {
        int sum = 0;
        int subarrayCount = 1;

        for (int &x : nums) {
            if(sum + x > mid){
                subarrayCount += 1;
                sum = x;
            }
            else
                sum += x;
        }
        return subarrayCount <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *max_element(begin(nums), end(nums));
        int r = accumulate(begin(nums), end(nums), 0);
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(canSplit(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};