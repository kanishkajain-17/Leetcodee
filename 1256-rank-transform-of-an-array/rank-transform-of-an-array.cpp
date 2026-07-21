class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i ++) 
            pq.push({arr[i], i});

        int prev = INT_MIN;
        int rank = 1;

        while (!pq.empty()) {

            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if(prev != val) {

                arr[idx] = rank;
                rank += 1;
            }
            else
                arr[idx] = rank - 1;
            prev = val;
        }
        return arr;
    }
};