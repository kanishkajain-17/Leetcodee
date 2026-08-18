class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int l = 0, r = 0;
        int count[256] = {0};
        int ans = 0;
        while (r < n) {

            count[s[r]] += 1;

            while (count[s[r]] > 1) {

                count[s[l]] -= 1;
                l += 1;
            }
            ans = max(ans, r - l + 1);
            r += 1;
        }
     return ans;
    }
};