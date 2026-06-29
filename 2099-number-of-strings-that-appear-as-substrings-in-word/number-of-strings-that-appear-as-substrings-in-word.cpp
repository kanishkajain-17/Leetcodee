class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (int i = 0; i < patterns.size(); i ++) {

            string temp = patterns[i];
            if(word.find(temp) != string :: npos) {
                count += 1;
            }
        }
        return count;
    }
};