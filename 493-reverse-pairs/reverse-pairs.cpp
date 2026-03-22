class Solution {
public:

    int countPairs(vector<int>& arr, int start, int mid, int end){
        int count = 0;
        int j = mid + 1;

        for(int i = start; i <= mid; i++){
            while(j <= end && arr[i] > 2LL * arr[j]){
                j++;
            }
            count += (j - (mid + 1));
        }
        return count;
    }

    void merge(vector<int> &arr, int start, int mid, int end){
        vector<int> temp;
        int i = start, j = mid + 1;

        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= end) temp.push_back(arr[j++]);

        for(int idx = 0; idx < temp.size(); idx++){
            arr[start + idx] = temp[idx];
        }
    }

    int mergeSort(vector<int> &arr, int start, int end){
        if(start >= end) return 0;

        int mid = (start + end) / 2;

        int count = 0;
        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid + 1, end);

        // ✅ Count BEFORE merge
        count += countPairs(arr, start, mid, end);

        merge(arr, start, mid, end);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};