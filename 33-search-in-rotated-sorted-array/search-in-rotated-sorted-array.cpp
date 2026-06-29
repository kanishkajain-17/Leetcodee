class Solution {
public:
    int findPivot(vector<int>& nums, int l, int r) {

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

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == x)
                return mid;
            else if(nums[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums, 0, n - 1);

        int idx = -1;
        idx = binary(nums, 0, pivot - 1, target);

        if(idx != -1)
            return idx;

        return idx = binary(nums, pivot, n - 1, target);
    }
};