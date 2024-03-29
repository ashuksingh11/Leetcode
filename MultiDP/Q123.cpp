//123. Best Time to Buy and Sell Stock III
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150

//generic solution
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/149383/Easy-DP-solution-using-state-machine-O(n)-time-complexity-O(1)-space-complexity/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }

        int s1=-prices[0], s2=INT_MIN, s3= INT_MIN, s4=INT_MIN;

        for(int i=1; i<prices.size(); i++) {
            s1 = max(s1,-prices[i]);
            s2 = max(s2, s1+prices[i]);
            s3 = max(s3, s2-prices[i]);
            s4 = max(s4, s3+prices[i]);
        }

        return max(0,s4);
    }
};
