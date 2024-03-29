//https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = nums[0];
        int count = 0;
        for (int i=0; i<nums.size(); i++ ) {
            if (count == 0 )
                e = nums[i];
            if(e == nums[i]) {
                count += 1;
            }
            else
                count -= 1;
        }

        return e;
    }
};