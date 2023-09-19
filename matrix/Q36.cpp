//https://leetcode.com/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150
//36. Valid Sudoku

//maintain row and col map iterate through all and set value in map
// 3x3 grid is same as (row/3)*3+(col/3)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowmap[9][9] = {0}, colmap[9][9] = {0}, grid3x3map[9][9]={0};

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = (i/3)*3+(j/3);

                    if(rowmap[i][num] == 1 || colmap[j][num] == 1 || grid3x3map[k][num] == 1) {
                        return false;
                    }

                    rowmap[i][num] = colmap[j][num] = grid3x3map[k][num] = 1;
                }
            }
        }

        return true;
    }
};