class Solution {
public:
    vector<string>ans;
    void solve(string & temp, int open, int close, int n){
        if(temp.size() == 2 * n){
            ans.push_back(temp);
            return;
        }
        else{
            if(open < n){
                temp += '(';
                solve(temp, open + 1, close, n);
                temp.pop_back();
            }
            if(open > close){
                temp += ')';
                solve(temp, open, close + 1, n);
                temp.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string temp = "";
        solve(temp, open, close, n);
        return ans;
    }
};