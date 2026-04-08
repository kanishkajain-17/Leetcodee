class Solution {
public:
    int M = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto & que : queries){
            int l = que[0];
            int r = que[1];
            int k = que[2];
            int v = que[3];

            while(l <= r){
                nums[l] = (1LL * nums[l] * v) % M;
                l += k;
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)    
            ans ^= nums[i];
        return ans;
    }
};