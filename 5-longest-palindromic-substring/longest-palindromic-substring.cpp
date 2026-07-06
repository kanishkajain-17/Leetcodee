class Solution {
public:
    string solve(string s, int left, int right) {

        while (left >= 0 && right < s.length() && s[left] == s[right]) {

            left -= 1;
            right += 1;
        }

        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {

        int n = s.length();
        string temp = "";

        for (int i = 0; i < n; i ++) {

            string odd = solve(s, i, i + 1);
            string even = solve(s, i, i);

            if(temp.length() < even.length())
                temp = even;
            if(temp.length() < odd.length())    
                temp = odd;
        }   
        return temp;
    }
};