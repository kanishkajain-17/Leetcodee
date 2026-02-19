class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        vector<int>ans(26, 0);

        for(int i = 0; i < s.length(); i++){
            ans[s[i] - 'a']++;
            ans[t[i] - 'a']--;
        }
        for(int c : ans)
            if(c != 0 )    
                return false;
        return true;
    }
};