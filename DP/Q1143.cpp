//1143. Longest Common Subsequence
//https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    vector<vector<int>> memo;
    int dp(string& text1, string& text2, int i, int j) {
        if(i==0 || j==0) {
            return 0;
        }    
        
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int ans;
        if(text1[i-1] == text2[j-1]) {
            ans =  1+dp(text1,text2,i-1,j-1);
        }
        else {
            ans = max(dp(text1,text2,i-1,j), dp(text1,text2,i,j-1));
        }
        
        memo[i][j] = ans;
        return memo[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        
        memo.resize(t1+1, vector<int>(t2+1,-1));
        
        return dp(text1,text2,t1,t2);
        
    }
};


//////bottom up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        
        vector<vector<int>> dp(t1+1, vector<int>(t2+1,0));

        for(int i=t1-1; i>=0; i--) {
            for(int j=t2-1; j>=0; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
        
    }
};
