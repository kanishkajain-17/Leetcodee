class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int result = 0;
        for(int cur = 0; cur < 32; cur++){
            if(((n >> cur) & 1) > 0){
                result = (prev != -1) ? max(result, cur - prev) : result;
                prev = cur;
            }
        }
        return result;
    }
};