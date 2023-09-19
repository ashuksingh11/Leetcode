//139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(), false);

        for(int i=0; i<s.size(); i++) {
            for(auto word: wordDict) {
                if(i < word.size()-1) {
                    continue;
                }

                if(i == word.size()-1 || dp[i-word.size()]) {
                    if(s.substr(i-word.size()+1, word.size()) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()-1];
    }
};

//top - down
class Solution {
public:
    vector<int> memo;
    vector<string> wordDict;
    string s;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return dp(s.length() - 1);
    }
    
    bool dp(int i) {
        if (i < 0) return true;
        
        if (memo[i] != -1) {
            return memo[i] == 1;
        }
        
        for (string word: wordDict) {
            int currSize = word.length();
            // Handle out of bounds case
            if (i - currSize + 1 < 0) {
                continue;
            }

            if (s.substr(i - currSize + 1, currSize) == word && dp(i - currSize)) {
                memo[i] = 1;
                return true;
            }
        }
        
        memo[i] = 0;
        return false;
    }
};
