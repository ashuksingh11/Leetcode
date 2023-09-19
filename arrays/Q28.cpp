//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150
//28. Find the Index of the First Occurrence in a String

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

class Solution {
public:
    int strStr(string haystack, string needle) {
        // use two pointer approach
        int m = haystack.size();
        int n = needle.size();

        if(n > m) return -1;

        for(int i = 0; i <= (m-n); i++) {
            int j = 0;
            for(j=0; j < n; j++) {
                if (needle[j] != haystack[j+i]){
                    break;
                }
            }
            if(j == n)
                return i;
        }

        return -1;
    }
};