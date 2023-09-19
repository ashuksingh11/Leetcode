//53. Maximum Subarray
//https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currmax = 0;
        int maxsum = INT_MIN;

        for(int num:nums) {
            currmax = max(currmax+num, num);
            maxsum = max(maxsum, currmax);
        }

        return maxsum;

    }
};
