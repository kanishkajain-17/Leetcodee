class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //sabse bade wale number ko sabse chote wale ke sath pair krdo so that we get minimum sum
        //isly sorting krdo
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        int ans = INT_MIN;
        while(i < j){
            int sum = nums[i] + nums[j];
            ans = max(ans, sum);
            i++;
            j--;
        }
        return ans;
    }
};