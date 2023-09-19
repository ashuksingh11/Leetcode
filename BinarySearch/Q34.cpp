//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//34. Find First and Last Position of Element in Sorted Array


//use two binary search first to find lower bound and then upper bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findbound(nums,target, true);
        if(first == -1) {
            return {-1,-1};
        }

        int sec = findbound(nums,target, false);

        return {first, sec};
    }

    int findbound(vector<int>& nums, int target, bool isLower) {
        int left = 0, right = nums.size()-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) {
                if(isLower) {
                    if(mid == left || nums[mid-1] != target) {
                        return mid;
                    }

                    right = mid - 1;
                }
                else {
                    if(mid == right || nums[mid+1] != target) {
                        return mid;
                    }

                    left = mid + 1;
                }
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid+1;
            }
        }

        return -1;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerbound(nums,target);
        int upper = lowerbound(nums,target+1) - 1;

        if(lower < nums.size() && nums[lower] == target) {
            return {lower, upper};
        }

        return {-1,-1};
    }

    int lowerbound(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;

            if(nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }

        return left;
    }
};