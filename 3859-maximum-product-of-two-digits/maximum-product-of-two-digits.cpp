class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;

        while (n > 0) {

            int val = n % 10;
            pq.push(val);

            if(pq.size() > 2)
                pq.pop();
            n = n / 10;
        }
        int ans = 1;
        while (!pq.empty()) {
            ans *= pq.top();
            pq.pop();
        }
        return ans;
    }
};