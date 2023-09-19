//https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
//219. Contains Duplicate II
// Input: nums = [1,2,3,1], k = 3
// Output: true

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {
            if (mp.count(nums[i])) {
                // this num was already seen check for cond
                if(abs(i - mp[nums[i]]) <= k) {
                    return true;
                }

               
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};