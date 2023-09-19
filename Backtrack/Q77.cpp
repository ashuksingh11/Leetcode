//77. Combinations


class Solution {
public:
    int n,k;
    vector<vector<int>> combine(int _n, int _k) {
        n = _n;k=_k;
        vector<int> curr;
        vector<vector<int>> ans;

        backtrack(curr,1,ans);

        return ans;
    }

    void backtrack(vector<int>& curr, int firstnum, vector<vector<int>>& ans) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int num = firstnum; num <= n; num++) {
            curr.push_back(num);
            backtrack(curr,num+1,ans);
            curr.pop_back();
        }
    }
};