class Solution {
public:
    int good(int n){
        bool changed = false;
        while(n > 0){
            int num = n % 10;
            if(num == 2 || num == 5 || num == 6 || num == 9)
                changed = true;
            else if(num == 3 || num == 4 || num == 7)
                return false;
            n = n / 10;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(good(i))
                count++;
        }
        return count;
    }
};