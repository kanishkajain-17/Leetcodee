class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x = x / 10;
            }
            if(sum == i)
                mini = min(mini, i);
        }
        return mini == INT_MAX ? -1 : mini;
    }
};