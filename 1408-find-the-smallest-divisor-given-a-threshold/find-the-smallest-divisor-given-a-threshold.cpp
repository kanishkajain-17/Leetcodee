class Solution {
public:
    bool canDivide(vector<int>& nums, int threshold, int mid) {
        long long sum = 0;
        for (int &x : nums) {
            sum += ceil((double)x / mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(begin(nums), end(nums));
        while (l < r) {
            int mid = l + (r - l) / 2;
            if(canDivide(nums, threshold, mid) == true)
                r = mid;
            
            else
                l = mid + 1;
        }
        return r;
    }
};