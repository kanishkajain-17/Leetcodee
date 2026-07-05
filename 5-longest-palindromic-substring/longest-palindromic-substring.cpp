class Solution {
public:
    bool check(string &s, int l, int r) {
        while(l < r) {
            if(s[l] == s[r]) {
                l += 1;
                r -= 1;
            }
            else
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        
        int n = s.length();
        int maxLen = 0;
        string ans = "";
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j++){
                if(check(s, i, j)) {

                    int len = j - i + 1;

                    if(len > maxLen) {

                        maxLen = max(maxLen, len);
                        ans = s.substr(i, len);
                    }                    
                }
            }
        }
        return ans;
    }
};