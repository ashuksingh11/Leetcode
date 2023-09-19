//https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150
//48. Rotate Image

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<=i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


//Intuition : for better understanding use 5x5 matrix and rotate it by 90 degree as 3x3 will not give complete picture. This is really imp to do use pen paper to draw both input output matrix first
//once you do this you will understand that if we move col wise in row 0 
// then we are basically rotating or swapping each element at corners for e.g (0,0)-> (0,4)  ; (0,4)-> (4,4)
// (4,4)->(4,0) and (4,0)->(0,0) then again we move colwise (0,1)-> (1,4)->(4,3)->(3,0)->(0,1). Now we can change our row (so col max will go till n/2). now rotate (1,0)->(0,3)->(3,4)->(4,1)->(1,0) we will continue for row till (n+1)/2 ie till middle.
// for coming up with calculation of swapping start out by choosing which element to store in tmp 
// and then how you will swap with others 


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<(n+1)/2; i++) {
            for(int j=0; j<n/2; j++) {
                int tmp = matrix[n - 1 - j][i]; //start by storing (4,0)
                matrix[n - 1 -j][i] = matrix[n - 1 - i][n - 1 - j]; // copy (4,0) = (4,4)
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]; // copy (4,4) = (0,4)
                matrix[j][n - 1 - i] = matrix[i][j]; //copy (0,4) = (0,0)
                matrix[i][j] = tmp; // copy (0,0) = tmp [i.e. 4,0]
            }
        }
    }
};