class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        int n = t.size();
        unordered_map<char, char>mp;
        set<char>st;
        for(int i = 0; i < n; i++){
            
            
                
             if(mp.find(t[i]) != mp.end()){
                char temp = mp[t[i]];
                cout<<temp;
                if(temp != s[i])
                    return false;
            }
            else if(st.find(s[i]) != st.end())
                return false;
            else{
                 mp[t[i]] = s[i];
                 st.insert(s[i]);
            }
               
        }
        return true;
    }
};