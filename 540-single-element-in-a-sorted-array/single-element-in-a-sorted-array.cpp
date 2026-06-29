class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        bool even = false;
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if((r - mid) % 2 == 0)
                even = true;
            else
                even = false;
            
            if(nums[mid] != nums[mid + 1]) {
                if(even == true)
                    r = mid;
                else
                    l = mid + 1;
            }
            else{
                if(even == true)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return nums[r];
    }
};