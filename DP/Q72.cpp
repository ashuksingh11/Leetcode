//72. Edit Distance
//https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        memo.resize(word1.size()+1, vector<int>(word2.size()+1, -1));

        return dp(word1,word2, word1.size(), word2.size());
    }

    int dp(string& word1, string& word2, int w1index, int w2index) {
        if(w1index == 0) {
            return w2index;
        }
        if(w2index == 0) {
            return w1index;
        }
        if(memo[w1index][w2index] != -1) {
            return memo[w1index][w2index];
        }

        int mineditdist = 0;
        if(word1[w1index-1] == word2[w2index-1]) {
            mineditdist = dp(word1,word2,w1index-1,w2index-1);
        }
        else {
            int rop = dp(word1, word2, w1index-1, w2index-1);
            int iop = dp(word1, word2, w1index, w2index-1);
            int dop = dp(word1, word2, w1index-1, w2index);

            mineditdist = min(rop, min(iop,dop)) + 1;
        }

        memo[w1index][w2index] = mineditdist;
        return mineditdist;
    }
};

//bootom up
    class Solution {
    public:
        int minDistance(string word1, string word2) {
            
            int w1 = word1.size();
            int w2 = word2.size();
            if(w1 == 0) {
                return word2.size();
            }

            if(w2 == 0) {
                return word1.size();
            }
            
            vector<vector<int>> dp(w1+1, vector<int>(w2+1, 0));

            for(int i=1; i<=w1; i++) {
                dp[i][0] = i;
            }

            for(int i=1; i<=w2; i++) {
                dp[0][i] = i;
            }

            for(int w1index=1; w1index<=w1; w1index++) {
                for(int w2index=1; w2index<=w2; w2index++) {
                    if(word1[w1index-1] == word2[w2index-1]) {
                        dp[w1index][w2index] = dp[w1index-1][w2index-1];
                    }
                    else {
                        dp[w1index][w2index] = min(dp[w1index][w2index-1], min(
                            dp[w1index-1][w2index], dp[w1index-1][w2index-1]
                        )) + 1;
                    }
                }
            }

            return dp[w1][w2];
        }

    };