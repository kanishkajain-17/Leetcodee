class Solution {
public:
    //tc = O(n * log(log n))
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        int count = 0;

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if(isPrime[i] == true) {

                for (int j = 2; i * j < n; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++)
            if(isPrime[i] == true)
                count += 1;
        return count;
    }
    
};