class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cur = j;
                int finalIdx;
                if(i % 2 == 0){//left shift
                    finalIdx = (j + k) % n; 
                }
                else//right shift
                    finalIdx = (j - k + n) % n;
                if(mat[i][cur] != mat[i][finalIdx])
                    return false;
            }
        }
        return true;
    }
};