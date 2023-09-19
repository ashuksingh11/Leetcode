class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int k=0;
        for(int i=2; i<nums.size(); i++) {
            if (nums[k] != nums[i]) {
                nums[k+2] = nums[i];
                k++;
            }
        }

        return k+2;
    }
};