class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxArea = INT_MIN;

        //NSL left to right
        stack<int> st;
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }

        //NSL right to left
        stack<int> temp;
        for (int i = n - 1; i >= 0; i--) {

            while (!temp.empty() && heights[temp.top()] > heights[i])
                temp.pop();
            if(temp.empty())
                right[i] = n;
            else
                right[i] = temp.top();
            temp.push(i);
        }

        for (int i = 0; i < n; i ++) {

            int dist = right[i] - left[i] - 1;
            int area = heights[i] * dist;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};