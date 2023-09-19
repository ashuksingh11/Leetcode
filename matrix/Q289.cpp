//https://leetcode.com/problems/game-of-life/?envType=study-plan-v2&envId=top-interview-150
//289. Game of Life

// brute force sol is to use a copy array to find out newly alive and newly dead
// to do inplace we can use values 2 (newly alive) or 3 (newly dead)

class Solution {
public:
int m;
int n;


    int getliveneighbors(vector<vector<int>> & board, int i, int j) {
        int ln=0;
        //up
        if(i>0) {
            if(board[i-1][j]==1 || board[i-1][j]==3 ) ln++;
        }
        //low
        if(i+1<m){
            if(board[i+1][j]==1 || board[i+1][j]==3 ) ln++;
        }
        //left
        if(j>0){
            if(board[i][j-1]==1 || board[i][j-1]==3 ) ln++;
        }

        //right
        if(j+1<n){
            if(board[i][j+1]==1 || board[i][j+1]==3 ) ln++;
        }

        //up-left
        if(i>0 && j>0){
            if(board[i-1][j-1]==1 || board[i-1][j-1]==3) ln++;
        }

        //up-right
        if(i>0 && j+1<n){
            if(board[i-1][j+1]==1 || board[i-1][j+1]==3) ln++;
        }

        //down-left
        if(i+1<m && j>0){
            if(board[i+1][j-1]==1 || board[i+1][j-1]==3) ln++;
        }

        //down-right
        if(i+1<m && j+1<n){
            if(board[i+1][j+1]==1 || board[i+1][j+1]==3) ln++;
        }        

        return ln;

    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int ln = getliveneighbors(board, i,j);

                if(board[i][j] == 0) {
                    //currently dead can become newly alive 
                    //if exactly 3 neighbors alive
                    if(ln == 3) {
                        board[i][j] = 2; //newly alive
                    }
                }
                else {
                    //currentlyy live can be dead if
                    //ln<2 || ln > 3
                    if(ln<2 || ln>3) {
                        board[i][j] = 3;// newly dead
                    }
                }
            }
        }

        //now change array 2->1 , 3->0
        for(int i = 0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 0;
                }                
            }
        }        
    }
};