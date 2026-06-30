class Solution {
public:
    bool canShip(vector<int>& weights, int mid, int days) {

        int sum = 0;
        int current_days = 1;
        int n = weights.size();
        for (int i = 0; i < n; i++) {

            sum += weights[i];

            if(sum > mid) {
                current_days += 1;
                sum = weights[i];
            }
        }
        return current_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int n = weights.size();
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0);
        int ans = 0;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if(canShip(weights, mid, days)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};