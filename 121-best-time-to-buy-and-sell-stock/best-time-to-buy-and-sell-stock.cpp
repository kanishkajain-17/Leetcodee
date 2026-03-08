class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = 0, profit = 0, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(mini, prices[i]);
            cost = prices[i] - mini;
            profit = max(cost, profit);
        }
        return profit;
    }
};