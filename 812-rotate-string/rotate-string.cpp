class Solution {
public:
    bool rotateString(string s, string goal) {
        
        goal += goal;
        int n = goal.length();

        for (int i = 0; i < n; i ++ ) {

            if(goal.find(s) != string :: npos)
                return true;
        }
        return false;
    }
};