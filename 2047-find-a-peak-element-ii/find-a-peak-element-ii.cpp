class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int m, int n, int col) {
        int maxVal = -1;
        int idx = -1;
        for (int i = 0; i < m; i ++) {
            if(mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int maxRowIndex = findMaxIndex(mat, m, n, mid);
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxRowIndex][mid + 1] : -1;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
                return {maxRowIndex, mid};
            else if(mat[maxRowIndex][mid] < left)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return {-1, -1};
    }
};