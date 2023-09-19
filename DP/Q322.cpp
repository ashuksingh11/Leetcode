//322. Coin Change
//https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150

    class Solution {
    public:
        vector<int> memo;
        int coinChange(vector<int>& coins, int amount) {
            if(amount < 1) return 0;
            memo.resize(amount+1,0);    

            return dp(coins,amount);
        }

        int dp(vector<int>& coins, int rem) {
            if(rem < 0) {
                return -1;
            }
            if(rem == 0){
                return 0;
            }

            if(memo[rem] != 0) {
                return memo[rem];
            }
            int mincount = INT_MAX;

            for(int coin:coins) {
                int res = dp(coins,rem-coin);
                if(res != -1) {
                    mincount = min(mincount,1+res);
                }
            }
            memo[rem] = (mincount == INT_MAX) ? -1 : mincount;
            return memo[rem];

        }
    };

    //bottom up
        class Solution {
    public:
        vector<int> memo;
        int coinChange(vector<int>& coins, int amount) {
            int max = amount + 1;
            vector<int> dp(amount+1, max);
            dp[0] = 0;
            for(int i=1; i<=amount; i++) {
                for(int j=0; j<coins.size(); j++) {
                    if(coins[j] <= i) {
                        dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                    }
                }
            }


            return dp[amount] > amount ? -1 : dp[amount];
        }
    };
