//22. Generate Parentheses

//https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backtrack(result,curr,0,0,n);

        return result;
    }

    void backtrack(vector<string>& result, string currstring, int leftcount, int rightcount, int n) {
        if(currstring.size() == 2*n) {
            result.push_back(currstring);
            return;
        }

        if(leftcount < n) {
            currstring.push_back('(');
            backtrack(result, currstring, leftcount+1, rightcount,n);
            currstring.pop_back();
        }

        if(leftcount > rightcount) {
            currstring.push_back(')');
            backtrack(result,currstring,leftcount,rightcount+1,n);
            currstring.pop_back();
        }
    }
};