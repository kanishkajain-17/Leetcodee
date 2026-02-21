class Solution {
public:
    string solve(string s ,int left, int right){

        while((left >= 0 && right < s.size()) && (s[left] == s[right])){
            
            left --;
            right ++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string temp = "";
        for(int i = 0; i < s.length(); i++){

            string even = solve(s, i, i+1);
            string odd = solve(s, i, i);

            if(even.length() > temp.length())
            temp = even;
            if(odd.length() > temp.length())
            temp = odd;
        }
        return temp;
    }
};