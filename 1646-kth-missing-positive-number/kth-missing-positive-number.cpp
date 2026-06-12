class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r= n - 1;
        while (l <= r) {
            int mid = l + (r - l) /2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k) //mtlb aur number aayenge abhi jo aapni position par nahi h
                l = mid + 1;
            else
                r = mid - 1;//jyda number aagaye
        }
        return l + k;
        //l + k -> l number toh already present the aab k number or chaiye toh simply add krdo bcz input is in sorted order
    }
};