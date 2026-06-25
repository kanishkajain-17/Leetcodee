class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int finalCount = 0;

        for (int i = 0; i < n; i ++) {
            int count = 0;
            for (int j = i; j < n; j ++) {

                int size = j - i + 1;

                if(nums[j] == target)
                    count += 1;
                if(count > size / 2)
                    finalCount += 1;

            }
        }
        return finalCount;
    }
};