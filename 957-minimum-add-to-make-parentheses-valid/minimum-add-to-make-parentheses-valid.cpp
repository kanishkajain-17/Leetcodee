class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int size = 0;
        int open = 0;

        for (int i = 0; i < n; i++) {
            if(s[i] == '(')
                size += 1;
            else if(size > 0)
                size -= 1;
            else
                open += 1;
        }
        return open + size;
    }
};