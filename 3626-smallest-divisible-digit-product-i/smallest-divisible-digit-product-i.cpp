class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int j = n; j <= n + 9; j ++) {

            int ans = 1;
            int i = j;
            while (i > 0) {

                ans *= i % 10;
                i /= 10;
            }
            if(ans % t == 0)
                return j;
        }
        return -1;
    }
};