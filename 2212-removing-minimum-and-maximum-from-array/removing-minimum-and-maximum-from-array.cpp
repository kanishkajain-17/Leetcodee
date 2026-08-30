class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxEle = max_element(begin(nums), end(nums)) - begin(nums);
        int minEle = min_element(begin(nums), end(nums)) - begin(nums);

        int left = min(maxEle, minEle);
        int right = max(maxEle, minEle);

        return min({(left + 1 + n - right), right + 1, n - left});
    }
};