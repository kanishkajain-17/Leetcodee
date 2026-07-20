class Solution {
public:
    bool isMatch(char a, char b) {

        if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
            return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i ++) {
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                
                if(st.empty())
                    return false;
                char temp = st.top();
                st.pop();

                if(isMatch(temp, s[i]) == false)
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};