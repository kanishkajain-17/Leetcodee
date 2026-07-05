class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < n; i ++) {

            mp[s[i]] += 1;
        }

        string ans = "";

        for (auto &ch : mp) {

            pq.push({ch.second, ch.first});
        }

        while (!pq.empty()) {

            int len = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            while (len--) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};