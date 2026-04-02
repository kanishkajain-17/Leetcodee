class Solution {
public:
    vector<int> getNSL(int & n, vector<int>& ht){
        
        stack<int>st;
        vector<int>left(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && ht[st.top()] >= ht[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        return left;
    }


    vector<int> getNSR(int & n, vector<int>& ht){
        
        stack<int>st;
        vector<int>right(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && ht[st.top()] >= ht[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        return right;
    }
    int findMaxArea(vector<int>&ht){
        int n = ht.size();
        vector<int>left = getNSL(n, ht);
        vector<int>right = getNSR(n, ht);

        vector<int>width(n);
        int maxArea = INT_MIN;

        for(int i = 0; i < n; i++){
            width[i] = right[i] - left[i] - 1;
            int area = ht[i] * width[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ht(n);

        for(int i = 0; i < n; i++)
            ht[i] = matrix[0][i] == '1' ? 1 : 0;

        int maxArea = findMaxArea(ht);

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0')
                    ht[j] = 0;
                else
                    ht[j] += 1;
            }
            maxArea = max(maxArea, findMaxArea(ht));
        }
        return maxArea;
    }
};