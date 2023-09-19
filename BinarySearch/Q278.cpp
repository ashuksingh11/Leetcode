//https://leetcode.com/problems/first-bad-version/description/
//278. First Bad Version



// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// we need to search for leftmost true;
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        while(left < right) {
            int mid = left + (right-left)/2;
            if(isBadVersion(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};