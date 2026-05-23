class Solution {
public:
    int find_pivot(vector<int>& nums, int n) {
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
    int binary_search(int l, int r, vector<int>& arr, int target) {
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) /2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] > target) 
                r = mid - 1;
            else
                l = mid + 1;        
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = find_pivot(nums, n);

        int idx = binary_search(0, pivot - 1, nums, target);
        if(idx != -1)
            return idx;
        idx = binary_search(pivot, n - 1, nums, target);
        return idx;

    }
};