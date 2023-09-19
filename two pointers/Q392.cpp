//https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=top-interview-150
//392. Is Subsequence
// Input: s = "abc", t = "ahbgdc"
// Output: true

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // use two pointers 
        int sl = s.size();
        int tl = t.size();
        int i=0,j=0;
        for (; i< tl && j < sl; i++) {
            if (s[j] == t[i]) j++;
        }

        return (j == sl);
    }
};