class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> mp;
        string ans = "";

        for (auto &s : knowledge) {
           // for (string &st : s) {
                mp[s[0]] = s[1];
            
        }

        for (int i = 0; i < n; i++) {
            if(s[i] == '(') {
                i += 1;
                string temp = "";
                while (s[i] != ')') {
                    temp += s[i];
                    i += 1;
                }
                if (mp.count(temp) == 0) {
                    ans += '?';
                    continue;
                }
                ans += mp[temp];
            }
            else
                ans += s[i];
        }
        return ans;
    }
};