//518. Coin Change II
//https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        memo.resize(coins.size(), vector<int>(amount+1,-1));

        return dp(coins, 0, amount);
    }

    int dp(vector<int>& coins, int i, int amt) {
        if(amt == 0) {
            return 1;
        }

        if(i == coins.size()) {
            return 0;
        }

        if(memo[i][amt] != -1) {
            return memo[i][amt];
        }

        if(coins[i] > amt) {
            memo[i][amt] = dp(coins, i+1, amt);
        }
        else {
            memo[i][amt] = dp(coins, i, amt-coins[i]) + dp(coins, i+1, amt);
        }

        return memo[i][amt];
    }
};

class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
        }

        for(int i=n-1; i>= 0; i--) {
            for(int j=1; j<=amount; j++) {
                if(coins[i] > j) {
                    dp[i][j] = dp[i+1][j];
                } 
                else {
                    dp[i][j] = dp[i+1][j] + dp[i][j-coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};