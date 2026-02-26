class Solution {
public:
    //dp[i][j] = number of ways to form first j characters of t using first i characters of s

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<double>>dp(m + 1, vector<double>(n + 1, 0));
        for(int i = 0; i <= m; i++){ //when j = 0 mtlb jo second string(t) hai saari string first wali se match hogyi hai toh count ko 1 kardo aur agar i = 0 mtlb first string (s1) mtlb ke string poori match nahi hui toh count 0 jo ke dp initialization ke time he kar diya 
            dp[i][0] = 1;
        }
        for(int j = 1; j <= n; j++)
            dp[0][j] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //agar match hogya toh uske aur combinations ko try karo like s = babgbag, t = bag toh jaise g match hogya last wale se lekin hume iske aur phle g bhi chaiye isly i-1 karo
                else
                    dp[i][j] = dp[i - 1][j];//first string mai peeche jaate jao
            }
        }
        return (int)dp[m][n];
    }
};