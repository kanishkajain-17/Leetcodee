class Solution {
public:
    //asked in manyyyyy companies
    int findPivot(vector<int>& nums, int l, int r) {
        while (l < r && nums[l] == nums[l + 1])
                l += 1;
            while (l < r && nums[r] == nums[r - 1])
                r -= 1;
        while (l < r) {
            
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
    bool binary(vector<int>& nums, int l, int r, int x) {

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == x)
                return true;
            else if(nums[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums, 0, n - 1);

        int idx = false;
        idx = binary(nums, 0, pivot - 1, target);

        if(idx != false)
            return true;

        return idx = binary(nums, pivot, n - 1, target);
    }
};