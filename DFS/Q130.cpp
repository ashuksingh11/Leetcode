//130. Surrounded Regions
//https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); 
        int n = board[0].size();

        //first and last cols
        for(int r=0; r<m; r++) {
            if(board[r][0] == 'O') {
                dfs(board,m,n,r,0);
            }
            if(board[r][n-1] == 'O') {
                dfs(board,m,n,r,n-1);
            }
        }

        //first and last row
        for(int c=0; c<n; c++) {
            if(board[0][c] == 'O') {
                dfs(board,m,n,0,c);
            }
            if(board[m-1][c] == 'O') {
                dfs(board,m,n,m-1,c);
            }
        }

        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if(board[r][c] == 'E') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int m, int n, int r, int c) {
        if(r<0 || r>= m || c<0 || c>=n || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'E';
        dfs(board,m,n,r+1,c);
        dfs(board,m,n,r-1,c);
        dfs(board,m,n,r,c+1);
        dfs(board,m,n,r,c-1);
    }
};