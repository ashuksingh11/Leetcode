//39. Combination Sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        backtrack(0, target, candidates, comb, ans);

        return ans;
    }

    void backtrack(int start, int remain, vector<int>& candidates, 
    vector<int>& comb, vector<vector<int>>& ans) {

        if(remain == 0) {
            ans.push_back(comb);
            return;
        }
        else if(remain < 0) {
            return;
        }

        for(int i=start; i<candidates.size(); i++) {
            comb.push_back(candidates[i]);
            backtrack(i, remain-candidates[i], candidates, comb, ans);
            comb.pop_back();
        }
    }
};