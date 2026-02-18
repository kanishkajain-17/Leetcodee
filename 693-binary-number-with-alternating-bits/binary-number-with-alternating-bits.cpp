class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0){
            int temp1 = n & 1;
            int temp2 = (n >> 1) & 1;
            if(temp1 == temp2)  
                return false;
            n = n >> 1;
        }
        return true;

    }
};