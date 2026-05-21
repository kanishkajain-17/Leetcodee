class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n)
            return "";

        unordered_map<char, int> mp;

        for (char &ch: t)
            mp[ch] += 1;
        
        int requiredCount = t.length();
        int i = 0, j = 0;
        int minWindowSize = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];

            if(mp[ch] > 0)
                requiredCount -= 1;
            mp[ch] -= 1;

            while (requiredCount == 0) {
                //shrinking karte raho 
                int curWindowSize = j - i + 1;
                if(minWindowSize > curWindowSize) {
                    minWindowSize = curWindowSize;
                    start_i = i;
                }
                //increase i and hence value in map also increase for that value of i
                mp[s[i]] += 1;
                if(mp[s[i]] > 0) { //means there is one char exists which is required for t (bcz we have increased the value of i) and we have removed it so increase requiredCount
                        requiredCount += 1;
                }
                i += 1;
            }
            j += 1;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};