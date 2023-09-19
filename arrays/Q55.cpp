//https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
//55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // lets imagine maxreach at every stage by computing i+nums[i]
        // we will reach any given index only if max reach was equal to
        // that value at previous step e.g. in example 2 to reach last index(4)
        // somewhere previously maxreach should have become 4 but it does not
        // so we cant reach end
        int maxreach = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i > maxreach) {
                return false; //we cant reach this index as maxreach never allowed us to be here
            }
            maxreach = max(maxreach, i+nums[i]);
        }

        return true;
    }
};

// backtracking with DP
class Solution {
public:
    vector<int> memo;

    bool canJump(vector<int>& nums) {
        memo.reserve(nums.size());
        //std::fill(memo.begin(), memo.end(), 0);
        for(int i=0; i<nums.size(); i++) {
            memo[i] = 0;
        }
        memo[nums.size()-1] = 1;

        return canJumpFromPosition(0, nums);
    }

    bool canJumpFromPosition(int pos, vector<int>& nums) {
        if(memo[pos] != 0) {
            return memo[pos] == 1 ? true : false ;
        }

        int farthestjump = min(pos+nums[pos], (int)nums.size()-1);
        for(int nextpos = pos+1; nextpos <= farthestjump; nextpos++) {
            if(canJumpFromPosition(nextpos, nums)) {
                memo[pos] = 1;
                return true;
            }
        }

        memo[pos] = 2;
        return false;
    }
};