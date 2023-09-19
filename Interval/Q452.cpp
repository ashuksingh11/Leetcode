// intuition: when reading problem we understand that we need to be greedy 
// also we need to sort to efficiently compute greedy, but sorting needs to be done by end 
// position
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) {
            return 0;
        }

        sort(points.begin(), points.end(), [](const vector<int>& o1, const vector<int>& o2) {
            return o1[1] < o2[1];
        });

        int xstart, xend, firstEnd = points[0][1];
        int arrows = 1;
        for(auto p:points){
            xstart = p[0];
            xend = p[1];

            //if the first ballon starts after end of another one
            // then we need one more arrow
            if(firstEnd < xstart) {
                ++arrows;
                firstEnd = xend;
            }
        }

        return arrows;
    }
};