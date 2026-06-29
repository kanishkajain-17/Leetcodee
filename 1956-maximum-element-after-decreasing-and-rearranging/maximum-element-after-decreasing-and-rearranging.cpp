class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(begin(arr), end(arr));
        int n = arr.size();
        int maxEle = 1;
        arr[0] = 1;

        for (int i = 1; i < n; i ++) {

            if(abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            maxEle = max(maxEle, arr[i]);
        }
        return maxEle;
    }
};