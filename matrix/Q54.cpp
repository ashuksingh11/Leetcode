//https://leetcode.com/problems/spiral-matrix/?envType=study-plan-v2&envId=top-interview-150
//54. Spiral Matrix
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// we need to take top,left,right,bottom then move like left->right, top->bottom
// right->left and bottom->top
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int top = 0, left = 0;
        int bottom = matrix.size()-1, right = matrix[0].size()-1;

        while(left <= right && top <= bottom) {

            for(int i=left; i<=right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top; i<=bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom) {
                for(int i=right; i>=left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for(int i=bottom; i>=top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};