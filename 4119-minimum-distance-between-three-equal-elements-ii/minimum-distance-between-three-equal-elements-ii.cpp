class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>>mp;

        for(int k = 0; k < n; k++){
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3){

                vector<int>& vec = mp[nums[k]];
                int sizee = vec.size();
                int i = vec[sizee - 3];

                ans = min(ans, 2 * (k - i));
            }
        }
    return ans == INT_MAX ? -1 : ans;
    }
};