class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char>st;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push('(');
            else{
                if(st.size() == 0)
                    count++;
                else
                    st.pop();
            }
        }
        if(!st.empty()){
            count += st.size();
        }
        return count;
    }
};