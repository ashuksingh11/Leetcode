class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i =0,j=0;
        for (int k =0; k< nums.size(); k++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;j++;
            }
            else {
                j++;
            }
        }

        return i;
    }
};