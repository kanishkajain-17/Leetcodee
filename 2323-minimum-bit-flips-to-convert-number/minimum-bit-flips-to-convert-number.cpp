class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int count = 0;

        while (temp > 0) {

            if((temp) & 1)
                count += 1;
            
            temp >>= 1;
        }
        return count;
    }
};