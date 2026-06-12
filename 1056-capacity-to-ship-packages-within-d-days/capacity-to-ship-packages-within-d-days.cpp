class Solution {
public:
    int canShip(vector<int> &weights, int mid, int day) {
        int sum = 0;
        int actualDay = 1;
        for (int &x : weights) {

            if(sum + x > mid) {
                actualDay += 1;
                sum = x;
            }
            else
                sum += x;
        }

        return actualDay;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0);

        while (l < r) {
            int mid = l + (r - l) / 2;
            if(canShip(weights, mid, days) <= days) //to isse aur choti value nikalne ka try kro 
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};