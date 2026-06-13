class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int, char> mp = 
        {{25, 'a'}, {24, 'b'}, {23, 'c'}, {22, 'd'}, {21, 'e'}, {20, 'f'}, {19, 'g'}, {18, 'h'}, {17, 'i'}, {16, 'j'}, {15, 'k'}, {14, 'l'}, {13, 'm'}, {12, 'n'}, {11, 'o'}, {10, 'p'}, {9, 'q'}, {8, 'r'}, {7, 's'}, {6, 't'}, {5, 'u'}, {4, 'v'}, {3, 'w'}, {2, 'x'}, {1, 'y'}, {0, 'z'}};
       
        int mod_val = 0;
        string ans = "";
        int n = words.size();

        for (int i = 0; i < n; i ++) {
            int sum = 0;
            string word = words[i];

            for (char &ch : word) {
                sum += weights[ch - 'a'];
            }
            mod_val = sum % 26;
            ans.push_back('z' - sum % 26);
        } 
        return ans;
    }
};