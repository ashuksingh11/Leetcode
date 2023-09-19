//276. Paint Fence
//https://leetcode.com/problems/paint-fence/description/

class Solution {
public:
    unordered_map<int,int> memo;
    int numWays(int n, int k) {
        return dp(n,k);
    }
    
    int dp(int i, int k) {
        if(i == 1) {
            return k;
        }
        if(i==2) {
            return k*k;
        }

        if(memo.find(i) != memo.end()) {
            return memo[i];
        }

        memo[i] = (k-1) * (dp(i-1,k) + dp(i-2,k));

        return memo[i];
    }
};

//bottom up
class Solution {
public:
    unordered_map<int,int> memo;
    int numWays(int n, int k) {
        if(n == 1) return k;
        if(n == 2) return k*k;

        vector<int> dp(n+1,0);

        dp[1] = k;
        dp[2] = k*k;

        for(int i=3; i<=n; i++) {
            dp[i] = (k-1) * (dp[i-1] + dp[i-2]);
        }

        return dp[n];
    }
    
};