class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i ++) {
            cur += gain[i];
            ans = max(cur, ans);
        }
        return ans;
    }
};