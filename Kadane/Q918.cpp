//918. Maximum Sum Circular Subarray
//https://leetcode.com/problems/maximum-sum-circular-subarray/description/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currmax = 0;
        int currmin = 0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        int totalsum = 0;

        for(int num:nums) {
            //normal kadane
            currmax = max(num, currmax+num);
            maxsum = max(maxsum, currmax);

            currmin = min(num, currmin+num);
            minsum = min(minsum, currmin);

            totalsum += num;
        }

        if(minsum == totalsum) {
            return maxsum;
        }

        return max(maxsum, totalsum-minsum);
    }
};
