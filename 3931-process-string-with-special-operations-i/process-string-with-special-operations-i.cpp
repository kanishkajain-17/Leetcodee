class Solution {
public:
    string processStr(string s) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i ++) {
            if(s[i] == '*'){
                if(!ans.empty())
                    ans.pop_back();
            }
            else if(s[i] == '#'){
                string temp = ans;
                ans.append(temp);
            }
            else if(s[i] == '%')    
                reverse(begin(ans), end(ans));
            else
                ans.push_back(s[i]);
        }
          return ans;
    }
  
};