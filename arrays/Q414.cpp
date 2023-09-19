class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int firstmax = -1, secondmax = -1, thirdmax = -1;
        bool fmax = false, smax = false, tmax = false;

        for(auto num: nums) {
            if( (fmax && firstmax == num) || 
                (smax && secondmax == num) ||
                (tmax && thirdmax == num)) {
                continue;
            }

            if(!fmax || firstmax <= num) {
                thirdmax = secondmax;tmax= smax;
                secondmax = firstmax;smax=fmax;
                firstmax = num;
                fmax = true;
            }
            else if(!smax || secondmax <= num) {
                thirdmax = secondmax;tmax = smax;
                secondmax = num;
                smax = true;
            }
            else if(!tmax || thirdmax <= num) {
                thirdmax = num;
                tmax = true;
            }
        }

        if(!tmax) {
            return firstmax;
        }

        return thirdmax;
    }
};