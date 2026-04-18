class Solution {
public:
    int getReverse(int n){
        int ans = 0;
        int n2 = 0, rev = 0;
        while(n > 0){
            n2 = n % 10;
            rev = (rev * 10) + n2;
            n = n / 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        return abs(n - getReverse(n));
    }
};