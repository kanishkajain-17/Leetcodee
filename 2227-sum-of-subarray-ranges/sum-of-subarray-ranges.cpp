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
            while(!st.empty() && nums[i] <= nums[st.top()])//<= to remove duplicacy of elements
                st.pop();
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        vector<int>NSL = getNSL(nums, n);
        vector<int>NSR = getNSR(nums, n);

        for(int i = 0; i < n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = ls * rs;
            long long totalSum = nums[i] * totalWays;
            sum = (sum + totalSum);
        }
        return sum;
    }


    vector<int>getNGL(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] > nums[st.top()])
                st.pop();
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>getNGR(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()])//>= to remove duplicacy of elements
                st.pop();
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        vector<int>NGL = getNGL(nums, n);
        vector<int>NGR = getNGR(nums, n);

        for(int i = 0; i < n; i++){
            long long ls = i - NGL[i];
            long long rs = NGR[i] - i;

            long long totalWays = ls * rs;
            long long totalSum = nums[i] * totalWays;
            sum = (sum + totalSum);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};