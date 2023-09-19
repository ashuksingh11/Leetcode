//https://leetcode.com/problems/majority-element-ii/description/
//229. Majority Element II
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // for brute force use maps
        // intuition there can be atmost 2 elements which are more than n/3
        // so we take 2 candidates and scan the array for candidates in 1sr scan
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        int count1 = 0, count2 =0;
        vector<int> result;

        for(int n: nums) {
            if(candidate1 == n){
                count1++;
            }
            else if(candidate2 == n) {
                count2++;
            }            
            else if(count1 == 0) {
                candidate1 = n;
                count1++;
            }
            else if(count2 == 0) {
                candidate2 = n;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(int n : nums) {
            if(candidate1 == n) { count1++;}
            if(candidate2 == n) { count2++;}
        }

        if(count1 > nums.size()/3) {
            result.push_back(candidate1);
        }
        if(count2 > nums.size()/3 ) {
            result.push_back(candidate2);
        }

        return result;
    }
};