class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.length();
        for(int i = 0; i < n; i++){
           while(ans.length() > 0 && ans.back() > num[i] && k > 0){
                ans.pop_back();
                k--;
               
           }
           if(ans.length() > 0 || num[i] != '0') //000123, 1123
                ans.push_back(num[i]);
        }
        //1111, 12345 all are increasing
        while(ans.length() > 0 && k > 0){
            ans.pop_back();
            k--;
        }
        if(ans == "") //all elements deleted
            return "0";
        return ans;
    }
};