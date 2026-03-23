class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 1; i <= 4; i++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i > j)
                        swap(mat[i][j], mat[j][i]);
                }
            }
            for(int i = 0; i < n; i++)
                 reverse(begin(mat[i]), end(mat[i]));
            if(mat == target)
                return true;
        }
        return mat == target;
    }
};