class Solution {
public:
    long long findSum(int n) {
        
        long long sum = 0;
        while (n > 0) {

            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }

    long long findNonZeroValue (int n) {

        long long val = 0;
        string num = to_string(n);
        int len = num.length();;

        for (int i = 0; i < len; i ++) {
            if(num[i] != '0') {
                val = (val * 10) + (num[i] - '0');
            }
        }
        return val;

    }
    long long sumAndMultiply(int n) {
        
        long long  x = 0;
        long long sum = 0;
        long long i = 0;
        
        x = findNonZeroValue(n);
        sum = findSum(n);
        cout <<x <<" " << sum;
        return x * sum;
    }
};