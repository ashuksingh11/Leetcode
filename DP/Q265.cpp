//265. Paint House II
//https://leetcode.com/problems/paint-house-ii/description/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();

        for(int i=n-2; i>=0; i--) {
            for(int color=0; color<k; color++) {
                int mincost = INT_MAX;
                for(int prevcolor=0; prevcolor<k; prevcolor++) {
                    if(color == prevcolor) {
                        continue;
                    }
                    mincost = min(mincost, costs[i+1][prevcolor]);
                }
                costs[i][color] += mincost;
            }
        }

        int mincost = INT_MAX;
        for(int c:costs[0]) {
            mincost = min(mincost,c);
        }

        return mincost;
    }
};
