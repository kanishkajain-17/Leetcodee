class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>nums;
        int n = numRows;
        for(int i = 0; i < n; i++){
            vector<int>row(i + 1, 1);
            for(int j = 1; j < i; j++){
                row[j] = nums[i - 1][j - 1] + nums[i - 1][j];
            }
            nums.push_back(row);
        }
        return nums;
    }
};