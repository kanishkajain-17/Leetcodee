class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long  minEle = *min_element(begin(nums), end(nums));
        long long maxEle = *max_element(begin(nums), end(nums));
        return (maxEle - minEle) * k;
    }
};