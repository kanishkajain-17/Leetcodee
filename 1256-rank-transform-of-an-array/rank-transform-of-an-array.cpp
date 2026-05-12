class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(begin(arr), end(arr));
        unordered_map<int, int> mp;
        int rank = 1;

        for (auto s : st) {
            mp[s] = rank++;
        }

        for(auto &i : arr) {
            i = mp[i]; //i is a reference to actual array element toh value automatiaclly change ho jayegi 
        }
        return arr;
    }
};