//448. Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int nindex = abs(nums[i])-1;
            if(nums[nindex] > 0) {
                nums[nindex] *= -1;
            }
        }

        for(int i=1; i<=nums.size(); i++) {
            if(nums[i-1] > 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};