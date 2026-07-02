class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(begin(s), end(s));
       
        string res = "";

        for (int i = 0; i < n; i ++) {
             string ans = "";
            while (s[i] == ' ')
                i += 1;
            while ((s[i] >= 'a' && s[i] <= 'z') ||( s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= '0' && s[i] <= '9'))) {
                ans.push_back(s[i]);
                i += 1;
            }
            reverse(begin(ans), end(ans));

            res.append(ans);
            res.push_back(' ');

        }
        int i = res.length() - 1;
        while (res[i] == ' ') {
            res.pop_back();
            i -= 1;
        }
        return res;
    }
};