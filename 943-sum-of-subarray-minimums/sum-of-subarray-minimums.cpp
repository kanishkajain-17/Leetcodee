class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {

        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i += 1) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>& arr, int n) {

        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i -= 1) {

            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(); 
        long long totalSum = 0;
        int M = 1e9 + 7;

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        for (int i = 0; i < n; i ++) {

            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = ls * rs;
            totalSum = (totalSum + (arr[i] * totalWays) % M) % M;
        }
        return totalSum;
    }
};