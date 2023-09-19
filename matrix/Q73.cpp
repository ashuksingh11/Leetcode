//https://leetcode.com/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-interview-150
//73. Set Matrix Zeroes
//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// use set to capture row and col which need to be set as zero
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_set<int> setrows;
        unordered_set<int> setcols;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == 0) {
                    setrows.insert(i);
                    setcols.insert(j);
                }
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(setrows.count(i) > 0 || setcols.count(j) > 0) {
                    matrix[i][j] = 0;
                }
            }
        }


    }
};


//use first row and col to store row,col pair
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isrow = false, iscol=false;
        int R = matrix.size();
        int C = matrix[0].size();

        for(int i=0;i<R; i++) {
            if(matrix[i][0] == 0) {
                iscol = true;
            }
        }

        for(int j=0; j<C;j++) {
            if(matrix[0][j] == 0) {
                isrow = true;
            }
        }

        for(int i=1; i<R; i++) {
            for(int j=1; j<C; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<R; i++) {
            for(int j=1; j<C; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i=0;i<R;i++) {
            if(iscol) {
                matrix[i][0] = 0;
            }
        }

        for(int i=0;i<C;i++) {
            if(isrow) {
                matrix[0][i] = 0;
            }
        }                 
    }
};