class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k, int n, vector<int>temp, int i, int sum){
        if(sum > n)
            return;
        if(k == 0 && sum == n){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j <= 9; j++){
            if(j > n)
                break;
            temp.push_back(j);
            solve(k - 1, n, temp, j + 1, sum + j);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k, n, temp, 1, 0);
        return ans;
    }
};