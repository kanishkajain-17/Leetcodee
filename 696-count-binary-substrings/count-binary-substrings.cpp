class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int prevCount = 0;
        int curCount = 1;

        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i - 1])
                curCount++;
            else{
                result += min(prevCount, curCount);
                prevCount = curCount;
                curCount = 1;
            }
        }
        return result + min(curCount, prevCount);
    }
};