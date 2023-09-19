//256. Paint House
//https://leetcode.com/problems/paint-house/description/

class Solution {
public:
    unordered_map<string, int> memo;
    vector<vector<int>> costs;
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) {
            return 0;
        }

        this->costs = costs;

        return min(dp(0,0), min(dp(0,1), dp(0,2)));
    }

    string getkey(int n, int color) {
        return to_string(n)+ " " + to_string(color);
    }

    int dp(int n, int color){
        if(memo.find(getkey(n,color)) != memo.end()) {
            return memo[getkey(n,color)];
        }

        int totalcost = costs[n][color];
        if(n == costs.size()-1) {
            return totalcost;
        }
        else if(color == 0) {
            totalcost += min(dp(n+1, 1), dp(n+1, 2));
        }
        else if(color == 1) {
            totalcost += min(dp(n+1, 0), dp(n+1, 2));
        }
        else {
            totalcost += min(dp(n+1, 1), dp(n+1, 0));
        }

        memo[getkey(n,color)] = totalcost;

        return totalcost;
    }
};

//bottom-up
// use prev row to further optimize for swpace
class Solution {
public:

    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) {
            return 0;
        }

        for(int i = costs.size()-2; i>=0; i--) {
             // Total cost of painting the nth house red.
            costs[i][0] += min(costs[i+1][1], costs[i+1][2]);
            // Total cost of painting the nth house green.
            costs[i][1] += min(costs[i+1][0], costs[i+1][2]);
            // Total cost of painting the nth house blue.
            costs[i][2] += min(costs[i+1][0], costs[i+1][1]);
        }

        return min(costs[0][0], min(costs[0][1], costs[0][2]));
    }

};