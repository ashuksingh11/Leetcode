//746. Min Cost Climbing Stairs
//https://leetcode.com/problems/min-cost-climbing-stairs/description/


class Solution {
public:
    unordered_map<int,int> memo;
    int dp(vector<int>& cost, int i) {
        if(i <= 1) {
            return 0;
        }

        if(memo.find(i) != memo.end()) {
            return memo[i];
        }

        memo[i] = min(cost[i-1]+dp(cost, i-1), cost[i-2]+dp(cost, i-2));

        return memo[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return dp(cost, cost.size());
    }
};

//bottom up
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);

        for(int i=2; i<dp.size(); i++) {
            int onestep = cost[i-1] + dp[i-1];
            int twostep = cost[i-2] + dp[i-2];
            dp[i] = min(onestep, twostep);
        }

        return dp[dp.size()-1];

    }
};