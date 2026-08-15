class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int XOR = 0;
        bool allZero = true;

        for (int i = 0; i < n; i++) {

            XOR ^= nums[i];

            if(nums[i] != 0)
                allZero = false;
        }
        if(allZero == true)
            return 0;
        
        return XOR == 0 ? n - 1 : n;
    }
};