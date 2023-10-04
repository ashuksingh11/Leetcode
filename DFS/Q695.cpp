//695. Max Area of Island
//https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxarea = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid,i,j,area, visited);
                    maxarea = max(maxarea,area);
                }
            }
        }
        
        return maxarea;
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, int& area, vector<vector<bool>>& visited) {
        
        visited[r][c] = true;
        area++;
        
        for(int i=0; i<4; i++) {
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size()) {
                continue;
            }            
            
            if(!visited[nr][nc] && grid[nr][nc] == 1) {
                dfs(grid, nr,nc,area,visited);
            }
        }
    }
};