class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char>st;
        for(int i = 0; i < s.length(); i++){
             
            if(s[i] == '(')
                st.push('(');
            if(st.size() > 1)
                   ans.push_back(s[i]);
            if(s[i] == ')'){
                st.pop();
            }
           
            
        }
        return ans;
    }
};