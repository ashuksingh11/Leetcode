//https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
//11. Container With Most Water


class Solution {
public:
    int maxArea(vector<int>& height) {
        // https://www.youtube.com/watch?v=UuiTKBwPgAo
        // use two pointer from left and right find max area 
        // then move from left or right based on height which is less

        int l=0, r=height.size()-1, maxarea=0;
        while(l < r) {
            int area = (r-l)*min(height[l], height[r]);
            maxarea = max(maxarea, area);
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxarea;
    }
};