class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        int carry = 0;
        int sum = 0;
        string ans = "";
    
        while(n >= 0 || m >= 0){
            
            sum = carry;
            
            if(n >= 0){
                sum += a[n] - '0';
                n--;
            }
            if(m >= 0){
                sum += b[m] - '0';
                m--;
            }
            ans.push_back((sum % 2 == 0) ? '0' : '1');
            carry = (sum > 1) ? 1 : 0;
        }
        if(carry == 1)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};