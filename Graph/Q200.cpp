//https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150
//200. Number of Islands

//we start from one point and run dfs and mark 1 to 0
//once all 1's are exhausted means we are traverlled all islands
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numofislands = 0;
        int m=grid.size(); int n=grid[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    numofislands++;
                    dfs(grid, m, n, i, j);
                }
            }
        }

        return numofislands;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j) {
        //check if in valid bounds
        if(i<0 || i>=m || j<0 || j>=n) {
            return;
        }

        if(grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, m,n,i-1,j);
            dfs(grid, m,n,i+1,j);
            dfs(grid, m,n,i,j-1);
            dfs(grid, m,n,i,j+1);
        }
    }
};