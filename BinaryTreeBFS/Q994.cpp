//994. Rotting Oranges
//https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int time = 0;
        int freshoranges = 0;
        vector<pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        queue<pair<int,int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    //rotten
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    freshoranges++;
                }
            }
        }

        while(freshoranges > 0 && !q.empty()) {
            int lsize = q.size();
            for(int i=0; i<lsize; i++) {
                pair<int,int> point = q.front();
                q.pop();
                int row = point.first;
                int col = point.second;

                for(auto d: dirs) {
                    int nrow = row + d.first;
                    int ncol = col + d.second;

                    if(isvalid(nrow,ncol,m,n) && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        freshoranges--;
                        q.push({nrow,ncol});
                    }
                }
            }

            time++;
        }

        if(freshoranges > 0) {
            return -1;
        }
        else {
            return time;
        }
    }

    bool isvalid(int r, int c, int m, int n) {
        if(r<0 || r>= m || c<0 || c>=n) {
            return false;
        }

        return true;
    }
};