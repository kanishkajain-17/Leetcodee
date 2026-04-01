class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;

        //left next smaller
        for(int i = 0; i < n; i++){
            while(!st.empty() && ht[st.top()] >= ht[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) //so that we can reuse the stack to calculate right smaller
            st.pop();

        //right next smaller
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && ht[st.top()] >= ht[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int curArea = ht[i] * width;
            ans = max(ans, curArea);
        }
        return ans;
    }
};