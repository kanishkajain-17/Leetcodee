class Solution {
public:
    vector<int>getNSL(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < nums[st.top()])
                st.pop();
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>getNSR(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int M = 1e9 + 7;
        
        vector<int>NSL = getNSL(nums, n);
        vector<int>NSR = getNSR(nums, n);

        for(int i = 0; i < n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = ls * rs;
            long long totalSum = nums[i] * totalWays;
            sum = (sum + totalSum) % M;
        }
        return sum;
    }
};