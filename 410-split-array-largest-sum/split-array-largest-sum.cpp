class Solution {
public:
    bool canSplit(vector<int>& arr, int mid, int k) {

        int n = arr.size();    
        int subarray_count = 1;
        int sum = 0;

        for (int i = 0; i < n; i ++) {

            sum += arr[i];
            if(sum > mid) {
                subarray_count += 1;
                sum = arr[i];
            }
        }
        return subarray_count <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        int l = *max_element(begin(arr), end(arr));
        int r = accumulate(begin(arr), end(arr), 0);
        int ans = 0;
        
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(canSplit (arr, mid, k)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};