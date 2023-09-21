//416. Partition Equal Subset Sum
//https://leetcode.com/problems/partition-equal-subset-sum/description/

//top-down memory limit exceeded
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(int n:nums) {
            totalsum += n;
        }

        if(totalsum%2 !=0) {
            return false;
        }
        int subsetsum = totalsum/2;
        int n = nums.size();

        vector<vector<int>> memo(n+1, vector<int>(subsetsum+1,-1));

        return dfs(nums, n-1, subsetsum, memo);
    }

    bool dfs(vector<int>& nums, int n, int subsetsum, vector<vector<int>>memo) {
        if(subsetsum == 0) {
            return true;
        }

        if(n==0 || subsetsum < 0) {
            return false;
        }

        if(memo[n][subsetsum] != -1) {
            return memo[n][subsetsum];
        }

        bool res = dfs(nums,n-1, subsetsum - nums[n], memo) || 
                    dfs(nums,n-1,subsetsum,memo);
        
        memo[n][subsetsum] = res;
        return res;
    }
};


//bottom up accepted
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(int n:nums) {
            totalsum += n;
        }

        if(totalsum%2 !=0) {
            return false;
        }
        int subsetsum = totalsum/2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1, vector<bool>(subsetsum+1,false));

        dp[0][0] = true;
        for(int i=1; i<=n; i++) {
            int curr = nums[i-1];
            for(int j=0; j<=subsetsum; j++) {
                if(j<curr) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-curr];
                }
            }
        }

        return dp[n][subsetsum];
    }

};

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        vector<bool> dp(subSetSum + 1, false);
        dp[0] = true;
        for (int curr : nums) {
            for (int j = subSetSum; j >= curr; j--) {
                dp[j] = dp[j] || dp[j - curr];
            }
        }
        return dp[subSetSum];
    }
};  