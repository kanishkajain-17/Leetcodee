class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int maxReachable = 0;
        int jump = 0;
        int curReach = 0;

        for (int i = 0; i < n - 1; i += 1) {

            maxReachable = max(maxReachable, i + nums[i]);

            if(i == curReach) {
                jump += 1;
                curReach = maxReachable;
            }

        }
        return jump;
    }
};