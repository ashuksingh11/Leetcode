//70. Climbing Stairs
//https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }

        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;


        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

//optimized
class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }

        int first = 1;
        int second = 2;
        int third = 0;

        for(int i=3; i<=n; i++) {
            third = first + second;
            first = second;
            second = third;
        }

        return second;
    }
};
