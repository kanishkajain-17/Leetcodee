class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prevPrev = 0;
        int curr = 0;
        int ans = 0;

        for(int i = 1; i < n; i++){
            int first = prevPrev + nums[i];
            int second = prev;
            curr = max(first , second);

            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};