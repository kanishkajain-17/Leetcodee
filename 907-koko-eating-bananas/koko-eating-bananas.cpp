class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {

        long count = 0;
        for (int i = 0; i < piles.size(); i ++) {
            count += piles[i] / mid;
        
            if(piles[i] % mid != 0)
                count += 1;
        }
        return count <= h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(begin(piles), end(piles));
        int n = piles.size();
        int l = 1;
        int r = *max_element(begin(piles), end(piles));
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if(canEat(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};