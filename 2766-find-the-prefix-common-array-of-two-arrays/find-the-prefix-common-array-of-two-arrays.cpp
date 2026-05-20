class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i += 1) {
            int count = 0;
            mp[A[i]] += 1;
            mp[B[i]] += 1;
            for (auto &it : mp) {
                if(it.second > 1) 
                    count += 1;
            }
            ans[i] = count;
        }
        return ans;
    }
};