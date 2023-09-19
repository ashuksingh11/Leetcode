//https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150
//128. Longest Consecutive Sequence

// approach 1 sort
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }

        sort(nums.begin(), nums.end());
        int maxstreak = 1;
        int currstreak = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] != nums[i]) {
                if(nums[i-1] +1 == nums[i]) {
                    currstreak++;
                }
                else {
                    maxstreak = max(maxstreak, currstreak);
                    currstreak = 1;
                }
            }
        }

        return max(currstreak, maxstreak);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.size() == 0) {
        //     return 0;
        // }

        unordered_set<int> myset;
        int currstreak = 0;
        int maxstreak = 0;

        for(auto num: nums) {
            myset.insert(num);
        }

        for(int num:nums) {
            if(myset.count(num-1) == 0) {
                int currnum = num;
                currstreak = 1;

                while(myset.count(currnum+1) > 0) {
                    currstreak++;
                    currnum++;
                }

                maxstreak = max(maxstreak,currstreak);
            }
        }

        return maxstreak;

    }
};