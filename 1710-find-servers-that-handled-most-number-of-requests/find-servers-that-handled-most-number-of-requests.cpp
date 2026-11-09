class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        // Initially, all servers are available
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishing time, server index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests have finished
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no server is available, drop the request
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int server = i % k;

            // Find the first available server >= preferred server
            auto it = available.lower_bound(server);

            // If none exists, wrap around to the smallest server
            if (it == available.end()) {
                it = available.begin();
            }

            // Assign request to the selected server
            int selected = *it;

            available.erase(it);

            count[selected]++;

            // Store its finishing time
            busy.push({arrival[i] + load[i], selected});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};