//https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150
//228. Summary Ranges

// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();

        vector<string> ans;

        string temp="";

        for(int i=0; i<n; i++) {
            int j = i;
            // move till next num is increment of 1
            while(j+1 < n && nums[j+1] == nums[j]+1) {
                j++;
            }

            //now we check if  there are more nums or just single
            if(j>i) {
                temp += to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            }
            else {
                temp += to_string(nums[j]);
            }

            //move i to j
            i=j;
            ans.push_back(temp);
            temp = "";

        }

        return ans;
    }
};