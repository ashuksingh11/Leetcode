//5. Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int ans[2] = {0};

        for(int i=0; i<n; i++) {
            dp[i][i] = true;
        }

        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans[0]=i;
                ans[1]=i+1;
            }
        }

        for(int diff = 2; diff<n; diff++) {
            //for string greater than 3
            for(int i=0; i<n-diff; i++) {
                int j = i+diff;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substr(i,j-i+1);
    }
};