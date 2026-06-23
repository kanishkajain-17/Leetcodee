class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majEle = 0;
        int count = 0;

        for (int i = 0; i < n; i ++) {

            if(count == 0) {
                majEle = nums[i];
                count += 1;
            }
            else if(nums[i] == majEle) 
                count += 1;
            else
                count -= 1;
        }   
        return majEle;
    }
};