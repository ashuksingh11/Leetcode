//https://leetcode.com/problems/single-number/submissions/?envType=study-plan-v2&envId=top-interview-150
//136. Single Number

//a^a^a......... (even times)=0 and a^a^a........(odd times)=a
// Why does this work ??
// Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            ans = ans^num;
        }

        return ans;
    }
};