class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        string ans;
        int n = goal.size();
        int i = 0;
        ans = s + s;
        
        
        while(i < n){
            if(goal == ans.substr(i, n))
                 return true;
            else
                 i++;
        }
       return false; 
        
    }
};