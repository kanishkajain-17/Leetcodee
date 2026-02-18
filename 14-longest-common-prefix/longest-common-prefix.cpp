class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs), end(strs));
        int n = strs.size();
        string start = strs[0];
        string last = strs[n - 1];
        string ans = "";
        for(int i = 0; i < start.length(); i++){
            if(start[i] == last[i])
                ans += start[i];
            else
                break;
        }
        return ans;
    }
};