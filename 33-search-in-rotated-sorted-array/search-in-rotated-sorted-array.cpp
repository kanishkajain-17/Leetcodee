class Solution {
public:
    int findPivot(vector<int>& nums, int n) {
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
    int binary(vector<int>& nums, int l, int r, int x) {
        while(l <= r) {
            int mid = l + (r - l) /2;
            if(nums[mid] == x)
                return mid;
            else if(nums[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int x) {
        int n = nums.size();
        int idx = -1;
        int pivot = findPivot(nums, n);
        idx = binary(nums, 0, pivot - 1, x);
        if(idx != -1)
            return idx;
        idx = binary(nums, pivot, n - 1, x);
        return idx;
    }
};