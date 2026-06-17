class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long l = 0; //length of final ans instead of calculating entire string
        for (int i = 0; i < n; i ++) {
            if(s[i] == '*') {
                if(l > 0)
                    l -= 1;
            }
            else if(s[i] == '#') 
                l *= 2;
            else if(s[i] == '%')
                continue;
            else
                l += 1;
        }
        if(k >= l)
            return '.';
        
        for (int i = n - 1; i >= 0; i-= 1) {
            if(s[i] == '*')
                l += 1;
            else if(s[i] == '#'){
                l = l / 2;
                k = (k >= l) ?  k - l : k;
            }
            else if(s[i] == '%')
                k = l - k - 1;
            else
                l -= 1;
            
            if(k == l)  
                return s[i];
        }
        return '.';

    }
};