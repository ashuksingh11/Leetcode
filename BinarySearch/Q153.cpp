//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// we need to find leftmost smallest number using binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, n = nums.size(), right = n-1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[n-1]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};