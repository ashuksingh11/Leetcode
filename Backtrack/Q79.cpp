//79. Word Search
//https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 1 && board[0][0] == word[0]) {
            return true;
        }


        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(word[0] == board[i][j]) {
                    if(dfs(board,word,i,j,0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int currindex) {
        if(r<0 || r>= board.size() || c<0 || c>=board[0].size()) {
            return false;
        }

        if(currindex == word.size()) {
            return true;
        }

        if(board[r][c] != word[currindex]) {
            return false;
        }

        board[r][c] = '#';
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        bool ret = true;
        for(int i=0;i<4;i++) {
            int nr = r+dr[i];
            int nc = c+dc[i];
            ret = dfs(board, word,nr,nc,currindex+1);
            if(ret) {
                break;
            }
        }

        //no match found 
        board[r][c] = word[currindex];
        return ret;
    }
};