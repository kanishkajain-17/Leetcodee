class Solution {
public:
     int findPivot(vector<int>& nums, int n) {
        int l = 0;
        int r = n - 1;
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
        while(l <= r) {
            int mid = l + (r - l) /2;
            if(nums[mid] == x)
                return true;
            else if(nums[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
    bool search(vector<int>& nums, int x) {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        bool found = binary(nums, 0, pivot - 1, x);
        if(found == true)
            return true;
        found = binary(nums, pivot, n - 1, x);
        return found;
    }
};