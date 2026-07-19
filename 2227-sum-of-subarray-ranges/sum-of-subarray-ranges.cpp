class Solution {
public:
    vector<int> getNSL(vector<int>& nums, int n) {

        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i ++) {

            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>& nums, int n) {

        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i -= 1) {

            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNGL(vector<int>& nums, int n) {

        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i ++) {

            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNGR(vector<int>& nums, int n) {

        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i -= 1) {

            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long getMinSum (vector<int>& nums, int n) {

        long long totalSum = 0;
        int M = 1e9 + 7;
        vector<int> NSL = getNSL(nums, n);
        vector<int> NSR = getNSR(nums, n);

        for (int i = 0; i < n; i ++) {

            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = ls * rs;
            totalSum = totalSum + (nums[i] * totalWays); 
        }
        return totalSum;
    }
    long long getMaxSum (vector<int>& nums, int n) {

        long long totalSum = 0;
        int M = 1e9 + 7;
        vector<int> NGL = getNGL(nums, n);
        vector<int> NGR = getNGR(nums, n);

        for (int i = 0; i < n; i ++) {

            long long ls = i - NGL[i];
            long long rs = NGR[i] - i;

            long long totalWays = ls * rs;
            totalSum = totalSum + (nums[i] * totalWays); 
        }
        return totalSum;
    }
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        long long minSum = getMinSum(nums, n);
        long long maxSum = getMaxSum(nums, n);

        return maxSum - minSum;
    }
};