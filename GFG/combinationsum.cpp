//https://www.geeksforgeeks.org/combinational-sum/
class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        // sort input array
        sort(A.begin(), A.end());
     
        // remove duplicates
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<int> r;
        vector<vector<int>> res;
        
        dfs(A, B, 0, r, res);
        
        return res;
    }
    
    void dfs(vector<int>& A, int sum, int idx, vector<int>& row, vector<vector<int>>& res) {
        if(sum < 0) {
            return;
        }
        
        if(sum == 0) {
            res.push_back(row);
            return;
        }
        
        for(int i=idx; i<A.size(); i++) {
            row.push_back(A[i]);
            
            dfs(A, sum-A[i], i, row, res);
            
            row.pop_back();
        }
    }
};