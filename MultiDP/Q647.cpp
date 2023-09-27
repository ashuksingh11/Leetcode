//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int count = 0;
        
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
        }
        
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
            }
        }
        
        for(int diff=2; diff<n; diff++) {
            for(int i=0; i<n-diff; i++) {
                int j = i+diff;
                if(s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][j]) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};