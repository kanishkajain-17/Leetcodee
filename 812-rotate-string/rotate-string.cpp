class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length() != goal.length())
            return false;
            
        string ans = s + s;
        int n = goal.length();
        int i = 0;

        while (i < n) {

            if(ans.substr(i, n) == goal)
                return true;
            i += 1;
        }
        return false;
    }
};