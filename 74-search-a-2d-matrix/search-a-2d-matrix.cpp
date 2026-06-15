class Solution {
public:
    // i starts at 0 and can go up to m-1 → at most m moves.
    // j starts at n-1 and can go down to 0 → at most n moves.
    // tc = O(m + n)
    // sc = O(1)
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;

        while (i < m && j >= 0) {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j -= 1;
            else
                i += 1;
        }
        return false;
    }
};