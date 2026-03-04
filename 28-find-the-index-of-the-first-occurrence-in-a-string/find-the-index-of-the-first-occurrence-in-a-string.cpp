class Solution {
public:
     void computeLPS(string needle, vector<int>& lps) {
        int M = needle.length();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {

        int N = haystack.length();
        int M = needle.length();
        vector<int> result;

        if (M > N) return -1;

        vector<int> lps(M, 0);
        computeLPS(needle, lps);

        int i = 0, j = 0;

        while (i < N) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }

            if (j == M) { //found
                return (i - j);  // 0-based index
               
            }
            else if (i < N && needle[j] != haystack[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};