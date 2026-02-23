class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int open = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                size++;
            else{
                if(size > 0)
                    size--;
                else
                    open++;
            }
        }
        return open + size;
    }
};