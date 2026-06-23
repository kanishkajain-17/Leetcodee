class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = prices[0];
        int profit = 0;
        int maxProfit = 0;

        for (int i = 1; i < n; i ++) {
           // cost = prices[i];
            profit = prices[i] - cost;
            maxProfit = max(profit, maxProfit);
            if(profit < 0)
                 cost = prices[i];
        }
        return maxProfit;
    }
};