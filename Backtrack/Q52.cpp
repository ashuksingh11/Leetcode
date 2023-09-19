//52. N-Queens II

class Solution {
public:
    int size;
    int totalNQueens(int n) {
        unordered_set<int> cols, diag,antidiag;
        size = n;

        return backtrack(0,cols,diag,antidiag);
    }

    int backtrack(int row, unordered_set<int>& cols, unordered_set<int>&diag,
    unordered_set<int>&antidiag) {
        if(row == size) {
            return 1;
        }

        int counts = 0;
        for(int col=0; col<size; col++) {
            int currdiag = row - col;
            int currantidiag = row+col;

            if(cols.count(col) || diag.count(currdiag) || 
            antidiag.count(currantidiag)) {
                continue;
            }

            cols.insert(col);
            diag.insert(currdiag);
            antidiag.insert(currantidiag);

            counts += backtrack(row+1, cols, diag,antidiag);

            cols.erase(col);
            diag.erase(currdiag);
            antidiag.erase(currantidiag);            
        }

        return counts;
    }
};
