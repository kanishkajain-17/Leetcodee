class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(begin(nums), end(nums));
        int n = nums.size();
        int j, k;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i ++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j += 1;
                    k -= 1;

                    while (j < k && nums[j] == nums[j - 1])
                         j += 1;
                }
                else if(sum < 0) 
                    j += 1;
                else
                    k -= 1;

               

            }

           
        }
        return ans;
    }
};