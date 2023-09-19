//120. Triangle
//https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int r=1; r< triangle.size(); r++) {
            for(int c=0; c<=r; c++) {
                int minabove = INT_MAX;
                if(c == 0) {
                    minabove = triangle[r-1][c];
                }
                else if(c == r) {
                    minabove = triangle[r-1][c-1];
                }
                else {
                    minabove = min(triangle[r-1][c-1], triangle[r-1][c]);
                }

                triangle[r][c] = minabove + triangle[r][c];
            }
        }
        int minpath = INT_MAX;
        for(int c=0; c<triangle.size(); c++) {
            minpath = min(minpath, triangle[triangle.size()-1][c]);
        }

        return minpath;
    }
};

//aux space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prevrow;
        prevrow.push_back(triangle[0][0]);

        for(int r=1; r< triangle.size(); r++) {
            vector<int> currRow;
            for(int c=0; c<=r; c++) {  
                int minabove = INT_MAX;
                if(c == 0) {
                    minabove = prevrow[c];
                }
                else if(c == r) {
                    minabove = prevrow[c-1];
                }
                else {
                    minabove = min(prevrow[c-1], prevrow[c]);
                }

                currRow.push_back(minabove + triangle[r][c]);
            }
            prevrow.clear();
            prevrow = currRow;
        }
        int minpath = INT_MAX;
        for(int c=0; c<triangle.size(); c++) {
            minpath = min(minpath, prevrow[c]);
        }

        return minpath;
    }
};