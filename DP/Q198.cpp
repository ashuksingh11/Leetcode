//198. House Robber
//https://leetcode.com/problems/house-robber/


class Solution {
public:
    unordered_map<int,int> memo;
    int dp(vector<int>& nums, int i) {
        if(i==0) {
            return nums[0];
        }
        
        if(i == 1) {
            return max(nums[0], nums[1]);
        }
        
        if(memo.find(i) != memo.end()) {
            return memo[i];
        }
        
        memo[i] = max(dp(nums, i-1), dp(nums, i-2)+nums[i]);
        
        return memo[i];
    }
    
    int rob(vector<int>& nums) {
        return dp(nums, nums.size()-1);
    }
};

//bottom up

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};