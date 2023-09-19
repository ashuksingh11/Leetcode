//1004. Max Consecutive Ones III

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxones =0;
        int zeros = 0;

        if(nums.size() == 0) {
            return 0;
        }

        for(int right =0; right<nums.size(); right++) {

            if(nums[right] == 0) {
                zeros++;
            }

            while(zeros > k) {
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            maxones = max(maxones, right-left+1);
        }

        return maxones;
    }
};