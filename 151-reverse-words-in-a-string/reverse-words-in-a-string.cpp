class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string temp = "";
        string ans = "";
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++){
            temp = "";
            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }
                
            reverse(begin(temp), end(temp));
            if(temp.length() > 0)
                 ans += ' ' + temp;
            
        }
        return ans.substr(1, n);
    }
};