class Solution {
public:
    bool checkBlanaced(vector<int>& freq){
        int commonFreq = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0)    
                continue;
            if(commonFreq == 0)
                commonFreq = freq[i];
            else if(freq[i] != commonFreq)
                return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            vector<int>freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                if(checkBlanaced(freq) == true)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};