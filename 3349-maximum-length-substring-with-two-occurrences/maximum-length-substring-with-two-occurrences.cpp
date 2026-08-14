class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        vector<int> count(26);
        while (r < n) {

            count[s[r] - 'a'] += 1;

            while (count[s[r] - 'a'] > 2) {
                count[s[l] - 'a'] -= 1;
                l += 1;
            }
            ans = max(ans, r - l + 1);
            r += 1;
        }
        return ans;
    }
};