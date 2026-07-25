class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int maxIdx = 0;
        int jump = 0;
        int curIdx = 0;

        for (int i = 0; i < n - 1; i ++) {

            maxIdx = max(maxIdx, i + nums[i]);

            if(i == curIdx) {

                jump += 1;
                curIdx = maxIdx;
            }
        }
        return jump;
    }
};