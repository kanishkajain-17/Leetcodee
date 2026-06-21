class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0)
            return;
        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums) + k);
        reverse(begin(nums) + k, end(nums));
    }
};