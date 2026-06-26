class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int a = 0;
        unordered_set<int> st;
        int b = 0;
        int acutalSum = 0;
        int expectedSum = 0;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if(st.find(grid[i][j]) != st.end()) {
                    a = grid[i][j];
                }
                else
                    st.insert(grid[i][j]);
               acutalSum += grid[i][j]; 
            }
        }
        expectedSum = ((n * n) * (n * n + 1)) / 2;
        b = expectedSum - acutalSum + a;
        return {a, b};
    }
};