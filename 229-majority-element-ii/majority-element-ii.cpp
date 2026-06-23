class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int ele1 = 0;
        int ele2 = 0;

        for (int i = 0; i < n; i++) {
            if(nums[i] == ele1)
                count1 += 1;
            else if(nums[i] == ele2)
                count2 += 1;
            else if(count1 == 0) {
                ele1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                ele2 = nums[i];
                count2 = 1;
            }
            else{
                count1 -= 1;
                count2 -= 1;
            }
        }
        int freq1 = 0;
        int freq2 = 0;
        vector<int> ans;

        for (int i = 0; i < n; i ++) {
            if(nums[i] == ele1)
                freq1 += 1;
            else if(nums[i] == ele2)
                freq2 += 1;
        }
        if(freq1 > floor(n / 3))
            ans.push_back(ele1);

        if(freq2 > floor(n / 3))
            ans.push_back(ele2);

        return ans;
    }
};