class Solution {
public:
    bool isMatch(char a, char b){
        if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
            return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                else{
                    char a = st.top();
                    st.pop();
                    if(!isMatch(a, s[i]))
                        return false;
              }
            }
        }
        return st.empty();
    }
};