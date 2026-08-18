class Solution {
public:
    //tc = O(2n) = O(n)
    //sc = O(1)
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1)
                nums[i] = 1;
            else
                nums[i] = 0;
        }

        int l = 0, r = 0;
        int count_zeros = 0;
        int ans = 0;
        int windowSum = 0;

        while (r < n) {

            windowSum += nums[r];

            while (l < r && (nums[l] == 0 || windowSum > k)) {

                if(nums[l] == 0)
                    count_zeros += 1;
                else
                    count_zeros = 0;
            
                windowSum -= nums[l];
                
                l += 1; 
            }

            if(windowSum == k) 
                ans += 1 + count_zeros;
             r += 1;
        }
        return ans;
    }
};