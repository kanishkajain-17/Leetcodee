class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> ans(n + 1);
        ans.push_back(0);
        int high = 0;
        
        for (int i = 1; i <= n; i ++) {

            ans[i] = ans[i - 1] + gain[i - 1];
            high = max(high, ans[i]);
        }
        return high;
    }
};