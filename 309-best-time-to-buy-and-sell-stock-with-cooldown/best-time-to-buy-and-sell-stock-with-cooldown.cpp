class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(3, 0);
        vector<int>cur(3, 0);

        for(int i = n - 1; i >= 0; i--){
            
                cur[1] = max(ahead[0] - prices[i], ahead[1]);
                cur[0] = max(ahead[2] + prices[i], ahead[0]);
                cur[2] = ahead[1];

                ahead = cur;
            }
            return ahead[1];
    }
};