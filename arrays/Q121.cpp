class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy at min price and sell at maxv price
        int n = prices.size();
        int buyPrice = INT_MAX;
        int maxprofit = 0;
        for(int i=0; i<n; i++) {
            buyPrice = min(buyPrice, prices[i]);
            maxprofit = max(maxprofit, prices[i] - buyPrice);
        }

        return maxprofit;
    }
};