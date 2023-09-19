//300. Longest Increasing Subsequence
//https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int longest = 0;
        for(int c:dp) {
            longest = max(longest,c);
        }

        return longest;
    }
};

//greedy with binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subseq;
        for(int x:nums) {
            if(subseq.empty() || subseq[subseq.size()-1] < x) {
                subseq.push_back(x);
            }
            else {
                auto it = lower_bound(subseq.begin(), subseq.end(), x);
                *it = x;
            }
        }

        return subseq.size();
    }
};