//64. Minimum Path Sum
//https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                // last row
                if(i == m-1 && j != n-1) {
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }
                else if(j == n-1 && i != m-1) {
                    //last col
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }
                else if (i != m-1 && j != n-1) {
                    // middle row cols
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
                }
                else {
                    dp[i][j] = grid[i][j];
                }
            }
        }

        return dp[0][0];
    }
};