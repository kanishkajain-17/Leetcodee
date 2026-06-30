class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] - (mid + 1) < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l + k;
    }
};