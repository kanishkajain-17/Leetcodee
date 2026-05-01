class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int F = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            F += i * nums[i];
        }
        int ans = F;
        for(int i = 0; i < n; i++){
            int new_f = F + sum - n * nums[n - 1 - i];
            ans = max(ans, new_f);
            F = new_f;
        }
        return ans;
    }
};