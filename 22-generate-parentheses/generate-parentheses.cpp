class Solution {
public:
    vector<string>ans;
    void solve(int n, string temp, int open, int close){
        if(temp.size() == 2 * n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            solve(n, temp, open + 1, close);
            temp.pop_back();
        } 
        if(open > close){
            temp.push_back(')');
            solve(n, temp, open, close + 1);
            temp.pop_back();
        } 
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        solve(n, "", open, close);
        return ans;
    }
};