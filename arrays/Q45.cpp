//45. Jump Game II
//https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150
//https://leetcode.com/problems/jump-game-ii/solutions/3781653/super-simple-solution/?envType=study-plan-v2&envId=top-interview-150

// we maintain farthest which is farthest we can reach from index
// we maintain current which represent current farthest we could have
// gotten here we update it if current index is same as current to farthest
// value as this is value we could have reached

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest =0, jumps=0, current=0;
        for(int i =0; i<nums.size()-1; i++) {
            farthest = max(farthest, nums[i]+i);
            if (i==current) {
                current = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};
