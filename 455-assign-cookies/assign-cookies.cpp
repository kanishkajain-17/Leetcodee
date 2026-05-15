class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(s), end(s));
        sort(begin(g), end(g));

        int n = g.size();
        int m = s.size();

        int i = 0, j = 0;
        int count = 0;

        while (i < n && j < m) {

            if(s[j] >= g[i]) {
                count += 1;
                i += 1;
            }
            j += 1;
        }
        return count;
    }
};