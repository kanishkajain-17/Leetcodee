class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(begin(nums), end(nums));
        int ans = k;

        while (st.count(ans) != 0) {
            ans += k;
        }
        return ans;
    }
};