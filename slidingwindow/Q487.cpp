//487. Max Consecutive Ones II
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxones = 0;
        int left = 0;
        int right = 0;
        int numzeros = 0;

        while(right<nums.size()) {
            if(nums[right] == 0) {
                numzeros++;
            }

            while(numzeros == 2) {
                if(nums[left] == 0) {
                    numzeros--;
                }
                left++;
            }

            maxones = max(maxones, right-left+1);
            right++;
        }

        return maxones;
    }
};