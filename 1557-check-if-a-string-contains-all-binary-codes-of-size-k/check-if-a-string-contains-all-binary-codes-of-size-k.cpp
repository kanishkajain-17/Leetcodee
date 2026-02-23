class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int totalNo = pow(2, k);
        int n = s.length();
        for(int i = k; i <= n; i++){

            string sub = s.substr(i - k, k);
            if(!st.count(sub)){
                st.insert(sub);
                totalNo--;
            }
                
            if(totalNo == 0)
                return true;
        }
        return false;
    }
};