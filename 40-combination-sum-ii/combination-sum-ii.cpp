class Solution {
public:
    
    vector<vector<int>>ans;
    void solve(vector<int>& candidates, int target, vector<int>temp, int i){
        if(target < 0)
            return;
       
        if(target == 0){
            ans.push_back(temp);
                return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j - 1])
                continue;
        

            temp.push_back(candidates[j]);
            solve(candidates, target - candidates[j], temp, j + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int>temp;
        solve(candidates, target, temp, 0);
        return ans;
    }
};