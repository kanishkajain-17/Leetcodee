class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>>pq;
        unordered_map<char, int>mp;
        int n = s.length();

        for(int i = 0; i < n; i++)
            mp[s[i]]++;
        for(auto & it : mp){
            pq.push({it.second, it.first});
        }
        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int i = it.first;
            while(i != 0){
                ans += it.second;
                i--;
            }
            
        }
        return ans;
    }
};