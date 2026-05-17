class Solution {
public:
    
    bool solve(vector<int>& arr, int idx, int n) {

       if(idx < 0 || idx >= n || arr[idx] < 0)
            return false;

         if(arr[idx] == 0)
            return true;

        arr[idx] *= -1;

        bool minus = solve(arr, idx - arr[idx], n);
        bool plus = solve(arr, idx + arr[idx], n);

        return minus || plus;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return solve(arr, start, n);
    }
};