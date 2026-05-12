class Solution {
public:
    typedef pair<int, int> p;
    vector<int> arrayRankTransform(vector<int>& arr) {

        priority_queue<p, vector<p>, greater<p>> pq;
        int n = arr.size();

        for (int i = 0; i < n; i += 1) {
            pq.push({arr[i], i});
        }

        int prev = INT_MIN;
        int rank = 1;

        while (!pq.empty()) {

            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            if(value != prev) {
                arr[index] = rank;
                rank += 1;
            }
            else
                arr[index] = rank - 1;
            
            prev = value; //for next's value calculation
        }
        return arr;
    }
};