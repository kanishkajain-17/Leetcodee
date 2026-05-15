class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;

        //from left to right for open
        for (int i = 0; i < n; i += 1) {
            if(s[i] == '(' || s[i] == '*')
                open += 1;
            else 
                open -= 1;
            if(open < 0)
                return false;
        }
        //from right to left close
        for (int i = n - 1; i >= 0; i -= 1) {
            if(s[i] == ')' || s[i] == '*')
                close += 1;
            else
                close -= 1;
            if(close < 0)
                return false;
        }
        return true;
    }
};