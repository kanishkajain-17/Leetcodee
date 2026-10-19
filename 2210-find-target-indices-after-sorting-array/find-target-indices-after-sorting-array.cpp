class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if(nums[i] < target)
                count1 += 1;
            else if(nums[i] == target)
                count2 += 1;
        }
        vector<int> ans;
        for (int idx = count1; idx < count1 + count2; idx++) {
            ans.push_back(idx);
        }
        return ans;
    }
};