class Solution {
public:
    int countPairs(vector<int>& nums, int st, int mid, int end) {

        int count = 0, j = mid + 1;
        for (int i = st; i <= mid; i += 1) {
            while (j <= end && (long long)nums[i] > (2LL * nums[j])) {
                j += 1;
            }
            count += j - (mid + 1);
        }
        return count;
    }

    void merge(vector<int>& arr, int st,int mid, int end) {

        vector<int> temp;
        int i = st, j = mid + 1;

        while (i <= mid && j <= end) {

            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i += 1;
            }
            else{
                temp.push_back(arr[j]);
                j += 1;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i]);
            i += 1;
        }
        while (j <= end) {
            temp.push_back(arr[j]);
            j += 1;
        }
        for (int idx = 0; idx < temp.size(); idx ++) {

            arr[st + idx] = temp[idx];
        }
     }
    int mergeSort(vector<int>& nums, int st, int end) {

        if(st < end) {

            int mid = st + (end - st) / 2;

            int leftCount = mergeSort(nums, st, mid);
            int rightCount = mergeSort(nums, mid + 1, end);

            int count = countPairs(nums, st, mid, end);

            merge(nums, st, mid, end);

            return leftCount + rightCount + count;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        return mergeSort(nums, 0, n - 1);

    }
};