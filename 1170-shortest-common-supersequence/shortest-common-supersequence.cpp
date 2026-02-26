class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= m; i++){ //index 0 se start kar rahe hai kyuki agar koi bhi ek string empty hai toh usme shortest common superseq jisme value badi hogi vo aayegi 
        // jaise s1 = "", s2 = "ab" toh common subseq ke length 2 hogi
            for(int j = 1; j <= n; j++){
                // if(i == 0 || j == 0)
                //     dp[i][j] = i + j;
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] =  max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
       string ans = "";
       int i = m;
       int j = n;

       while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else {
            if(dp[i][j - 1] < dp[i - 1][j]){
                ans.push_back(s1[i - 1]); //minimum value wale ko push karna hai
                i--;
            }
            else{
                ans.push_back(s2[j - 1]);
                j--;
            }
        }  
    }
       while(i > 0){
        ans.push_back(s1[i - 1]);
        i--;
       }

       while(j > 0){
        ans.push_back(s2[j - 1]);
        j--;
       }
       reverse(begin(ans), end(ans));
    return ans;
    }
};