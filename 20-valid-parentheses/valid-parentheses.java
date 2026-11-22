class Solution {
    public boolean isMatch(char a, char b) {

        if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
            return true;

        return false;
    }
    public boolean isValid(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < n; i++) {

            if(s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{')
                st.push(s.charAt(i));
            
            else {

                if(st.isEmpty())
                    return false;
                else {
                    char temp = st.peek();
                    st.pop();

                    if(isMatch(temp, s.charAt(i)) == false)
                        return false;
                }
            }
        }
        if(!st.isEmpty())
            return false;
        
        return true;
    }
}