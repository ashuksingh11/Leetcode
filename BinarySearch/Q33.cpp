//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//for one pass we find if left subarray is sorted or right subarray is sorted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            else if(nums[left] <= nums[mid]) {
                //left arr sorted
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid+1;
                }
            }
            else {
                //right arr sorted
                if(target <= nums[right] && target > nums[mid]) {
                    left = mid+1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};


// two pass O(n)
class Solution {
public:
    int binarysearch(vector<int>& nums, int lb, int rb, int target) {
        int l = lb, r = rb;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[n-1]) {
                left = mid+1;
            }
            else {
                right = mid - 1;
            }
        }

        int ans = binarysearch(nums, 0, left - 1, target);
        if(ans != -1) {
            return ans;
        }

        ans = binarysearch(nums,left, n-1, target);

        return ans;
    }
};