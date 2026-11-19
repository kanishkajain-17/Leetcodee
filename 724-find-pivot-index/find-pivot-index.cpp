class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixL(n);
        vector<int> prefixR(n);

        prefixL[0] = nums[0];
        prefixR[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefixL[i] = nums[i] + prefixL[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            prefixR[i] = nums[i] + prefixR[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if(prefixL[i] == prefixR[i])
                return i;
        }
        return -1;
    }
};