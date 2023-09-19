//https://leetcode.com/problems/two-sum/?envType=study-plan-v2&envId=top-interview-150
//1. Two Sum

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // use a unordered map and then find to complement
        unordered_map<int,int> umap;
        for(int i = 0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if(umap.find(complement) != umap.end()) {
                return {umap[complement], i};
            }
            umap[nums[i]] = i;
        }

        return {-1, -1};
    }
};