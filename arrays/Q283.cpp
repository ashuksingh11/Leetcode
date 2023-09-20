//283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonzeroat = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[lastnonzeroat], nums[i]);
                lastnonzeroat++;
            }
        }
    }
};