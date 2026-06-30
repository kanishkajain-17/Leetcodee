class Solution {
public:
    bool canDivide(vector<int>& nums, int mid, int threshold) {

        int sum = 0;

        for (int i = 0;i < nums.size(); i ++) {

            sum += ceil((double)nums[i] / mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1, r = *max_element(begin(nums), end(nums));
        int ans = 0;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if(canDivide(nums, mid, threshold)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};