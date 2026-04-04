class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.size();
        int col = l / rows;

        string originalText;
        for(int i = 0; i < col; i++){
            for(int j = i; j < l; j += (col + 1)){
                originalText += encodedText[j];
            }
        }
        while(!originalText.empty() && originalText.back() == ' ')
            originalText.pop_back();

        return originalText;
    }
};