//https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150
//15. 3Sum

//use intuition from two sum approach where we need to sort the array first
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= 0) {
                if (i==0 || nums[i-1] != nums[i]) {
                    twosumii(nums, i, res);
                }
            }
        }

        return res;
    }

    void twosumii(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i+1, hi = nums.size()-1;
        while(lo < hi) {
            int sum = nums[i]+nums[lo]+nums[hi];
            if(sum<0) {
                ++lo;
            }
            else if(sum > 0) {
                --hi;
            }
            else {
                res.push_back({nums[i],nums[lo],nums[hi]});
                lo++;hi--;
                while(lo<hi && nums[lo-1] == nums[lo]) {
                    ++lo;
                }
            }
        }
    }
};