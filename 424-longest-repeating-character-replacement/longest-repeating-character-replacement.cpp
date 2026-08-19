class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        int count[26] = {0};
        int maxFreq = 0;

        while (r < n) {

            count[s[r] - 'A'] += 1;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            int windowSize = r - l + 1;
            
            if (windowSize - maxFreq > k) {
                count[s[l] - 'A'] -= 1;
                l += 1;
            }
            ans = max(ans, r- l + 1);
            r += 1;
        }
        return ans;
    }
};