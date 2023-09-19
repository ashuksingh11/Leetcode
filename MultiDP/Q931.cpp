//931. Minimum Falling Path Sum
//https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:
    vector<vector<int>> memo;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        memo.resize(n, vector<int>(n,-1));
        int minfallingsum = INT_MAX;

        for(int c=0; c<n; c++) {
            minfallingsum = min(minfallingsum, dp(matrix,0,c));
        }

        return minfallingsum;
    }

    int dp(vector<vector<int>>& matrix, int r, int c) {
        if(c<0 || c==matrix.size()) {
            return INT_MAX;
        }

        if(r == matrix.size()-1) {
            return matrix[r][c];
        }

        if(memo[r][c] != -1) {
            return memo[r][c];
        }

        int left = dp(matrix,r+1,c-1);
        int mid = dp(matrix, r+1, c);
        int right = dp(matrix, r+1,c+1);

        int currmin = min(left,min(mid,right)) + matrix[r][c];

        memo[r][c] = currmin;
        return currmin;
    }
};

//bottom up working oslution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int row = n-1; row >= 0; row--) {
            for(int col = 0; col<n; col++) {
                if(col == 0) {
                    dp[row][col] = min(dp[row+1][col], dp[row+1][col+1]) +
                                    matrix[row][col];
                }
                else if(col == n-1) {
                    dp[row][col] = min(dp[row+1][col], dp[row+1][col-1]) +
                                    matrix[row][col];
                }
                else {
                    dp[row][col] = min(dp[row+1][col], min(dp[row+1][col-1],
                    dp[row+1][col+1])) + matrix[row][col];
                }
            }
        }

        int minans = INT_MAX;
        for(int col=0; col<n; col++) {
            minans = min(minans, dp[0][col]);
        }

        return minans;
    }
};
