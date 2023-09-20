//188. Best Time to Buy and Sell Stock IV
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k==0) {
            return 0;
        }

        vector<int> profit(k+1);
        vector<int> cost(k+1, INT_MAX);

        profit[0] = 0;
        for(int price:prices) {
            for(int i=0; i<k; i++) {
                cost[i+1] = min(cost[i+1], price-profit[i]);
                profit[i+1] = max(profit[i+1], price-cost[i+1]);
            }
        }
        
        return profit[k];
    }
};




//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/54125/Very-understandable-solution-by-reusing-Problem-III-idea/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k==0) {
            return 0;
        }

        vector<int> sell(k+1,0);
        vector<int> buy(k+1, INT_MIN);

        for(int price:prices) {
            for(int i=1; i<=k; i++) {
                buy[i] = max(buy[i], sell[i-1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        
        return sell[k];
    }
};