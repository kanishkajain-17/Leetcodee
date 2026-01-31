class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //MY SOLUTION--->>
        // for(int i = 0; i < letters.size(); i++){
        //     if(letters[i] != target && ((letters[i] - 'a') > (target - 'a')))
        //         return letters[i];
        // }
        // return letters[0];

        //USING BINARY SEARCH---->

        int l = 0;
        int r = letters.size() - 1;
        char ans = letters[0];

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(letters[mid] > target){
                r = mid - 1;
                ans = letters[mid];
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
        
    }
};