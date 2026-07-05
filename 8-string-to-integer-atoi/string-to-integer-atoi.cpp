class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        int sign = 1;
        long long ans = 0;
        while (i < n && s[i] == ' ') 
            i += 1;
        
        if(s[i] == '-' || s[i] == '+') {
            if(s[i] == '-')
                sign = -1;
            i += 1;
        }

        while (i < n && s[i] == '0')
            i += 1;
        while (i < n && s[i] >= '0' && s[i] <= '9') {

            ans = (s[i] - '0') + (ans * 10);
            i += 1;

             if(sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if(sign == - 1 && (-ans) < INT_MIN)
                return INT_MIN;
        }

       
        
        return (int)(ans * sign);
    }
};