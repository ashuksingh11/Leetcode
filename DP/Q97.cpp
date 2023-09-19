//97. Interleaving String
//https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));

        return dp(s1,s2,s3,0,0,0,memo);
    }

    bool dp(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& memo) {
        if(i == s1.size()) {
            return s2.substr(j) == s3.substr(k);
        }

        if(j == s2.size()) {
            return s1.substr(i) == s3.substr(k);
        }

        if(memo[i][j] >= 0) {
            return memo[i][j] == 1?true:false;
        }

        bool ans = false;
        if(s3[k] == s1[i] && dp(s1,s2,s3,i+1,j,k+1,memo) ||
            s3[k] == s2[j] && dp(s1,s2,s3,i,j+1,k+1,memo)) {
                ans = true;
        }

        memo[i][j] = ans ? 1:0;
        return ans;
    }
};

//bottom -up
class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        for(int i=0; i<=s1.size(); i++) {
            for(int j=0; j<=s2.size(); j++) {
                if(i==0 && j==0) {
                    dp[i][j] = true;
                }
                else if(i==0) {
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0) {
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else {
                    dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || 
                                (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        
        return dp[s1.size()][s2.size()];
    }


};