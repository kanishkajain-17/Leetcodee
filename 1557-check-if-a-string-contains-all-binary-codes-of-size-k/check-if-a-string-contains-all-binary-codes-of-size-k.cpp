class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k)
            return false;
        unordered_set<string>st;
        int totalNo = pow(2, k);
        int n = s.length();
        for(int i = 0; i <= n - k; i++){
            st.insert(s.substr(i, k));
        }
        return st.size() == totalNo;
    }
};