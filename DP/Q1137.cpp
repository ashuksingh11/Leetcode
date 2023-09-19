//1137. N-th Tribonacci Number
//https://leetcode.com/problems/n-th-tribonacci-number/description/


class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        
        if(n<3) {
            return n > 0 ? 1 : 0;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
};
