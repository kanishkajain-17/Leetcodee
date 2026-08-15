class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l < r) {
            swap(s[l], s[r]);
            l += 1;
            r -= 1;
        }
    }
};