//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
//1091. Shortest Path in Binary Matrix


class Solution {
public:
    bool isvalid(int r, int c, int n) {
        if(r<0 || r>=n || c<0 || c>=n) {
            return false;
        }

        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        q.push(make_pair(0,0));
        visited[0][0] = true;
        int currdistance = 1;
        int dirR[] = {-1,-1,-1,0,0,1,1,1};
        int dirC[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()) {
            int nodesAtCurrDistance = q.size();
            for(int i=0; i<nodesAtCurrDistance; i++) {
                pair<int,int> currcell = q.front();
                q.pop();
                int row = currcell.first;
                int col = currcell.second;
                if(row == n-1 && col == n-1) {
                    return currdistance;
                }

                for(int i=0; i<8; i++) {
                    int nrow = row + dirR[i];
                    int ncol = col + dirC[i];
                    if(isvalid(nrow,ncol,n) && grid[nrow][ncol] == 0 &&
                        !visited[nrow][ncol]) {
                            q.push(make_pair(nrow,ncol));
                            visited[nrow][ncol] = true;
                    }
                }
            }

            currdistance += 1;
        }

        return -1;
    }
};