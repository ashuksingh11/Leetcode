//84. Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxarea = 0;

        for(int i=0; i<heights.size(); i++) {
            while(st.top() != -1 && heights[st.top()] >= heights[i]) {
                int currheight = heights[st.top()];
                st.pop();
                int currwidth = i - st.top() - 1;
                maxarea = max(maxarea, currheight*currwidth);
            }
            st.push(i);
        }

        while(st.top() != -1) {
            int currheight = heights[st.top()];
            st.pop();
            int currwidth = heights.size() - st.top() -1;
            maxarea = max(maxarea, currwidth*currheight);
        }

        return maxarea;
    }
};