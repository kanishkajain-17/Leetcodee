class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if(s[i] == '(')
                open += 1;
            else
                close += 1;
            if(open == close)
                ans = max(ans, open + close);
            if(close > open) {
                open = 0;
                close = 0;
            }

        }
        open = 0, close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if(s[i] == '(')
                open += 1;
            else 
                close += 1;
            if(open == close)
                ans = max(ans, open + close);
            if(open > close) {
                open = 0, close = 0;
            }
        }
        return ans;
    }
};