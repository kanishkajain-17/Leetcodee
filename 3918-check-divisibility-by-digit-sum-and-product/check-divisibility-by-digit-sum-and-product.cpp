class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product =  1;
        int n1 = n;

        while (n1 > 0) {
            sum += n1 % 10;
            product *= n1 % 10;
            n1 = n1 / 10;
        } 
        if(n % (sum + product) == 0) {
            return true;
        }
        return false;
    }
};