class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(s), end(s));
        sort(begin(g), end(g));

        int m = g.size();
        int n = s.size();

        int i = 0, j = 0;
        int count = 0;

        while (i < m && j < n) {

            if(s[j] >= g[i]) {
                count += 1;
                i += 1;
            }
            j += 1;
        }
        return count;
    }
};