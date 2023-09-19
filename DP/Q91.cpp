//91. Decode Ways
//https://leetcode.com/problems/decode-ways/description/

class Solution {
public:
    unordered_map<int,int> memo;
    int numDecodings(string s) {
        return dp(s, 0);
    }

    int dp(string& s, int index) {
        if( index == s.size()) {
            return 1; //one way to decode
        }

        if(s[index] == '0') {
            return 0; //cnat decode 0
        }

        if(index == s.size()-1) {
            return 1;
        }

        if(memo.find(index) != memo.end()) {
            return memo[index];
        }

        int ans = dp(s, index+1);
        if(stoi(s.substr(index, 2)) <= 26) {
            ans += dp(s, index+2);
        }

        memo[index] = ans;

        return memo[index];
    }
};

//bottom up
class Solution {
public:
    unordered_map<int,int> memo;
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0:1;

        for(int i=2; i<dp.size(); i++) {
            if(s[i-1] != '0') {
                dp[i] = dp[i-1];
            }

            int two_digits = stoi(s.substr(i-2,2));
            if(two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[s.length()];
    }
};