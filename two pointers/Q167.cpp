//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
//167. Two Sum II - Input Array Is Sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i=0,j=len-1;
        vector<int> res;

        while(i<j) {
            if(numbers[i]+numbers[j] == target) {
                return {i+1,j+1};
            }
            else if(numbers[i]+numbers[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return res;
    }
};