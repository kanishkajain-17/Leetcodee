class Solution {
public:
    int findScore(int num) {
        string s = to_string(num);
        int l = s.length();
        if(l < 3)
            return 0;
        
        int score = 0;
        for (int i = 1; i <= l - 2; i += 1) {
            if(s[i] > s[i - 1] && s[i] > s[i + 1])
                score += 1;
            if(s[i] < s[i - 1] && s[i] < s[i + 1])
                score += 1;
        }
        return score;
    }
    int totalWaviness(int num1, int num2) {
        int score = 0;
        for (int num = num1; num <= num2; num += 1) {
            score += findScore(num);
        }
        return score;
    }
};