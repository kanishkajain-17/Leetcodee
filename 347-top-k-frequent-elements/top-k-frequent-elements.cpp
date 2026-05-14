class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<p, vector<p>, greater<p>> pq;

        for (int i = 0; i < n; i += 1) {
            mp[nums[i]] += 1;
        }
        
        for (auto &it : mp) {

            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};