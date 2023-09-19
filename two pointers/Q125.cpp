//https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150
//125. Valid Palindrome
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i=0,j=len-1;

        while(i<j) {
            if(!isalnum(s[i])) {
                i++;
            }
            else if(!isalnum(s[j])) {
                j--;
            }
            else if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            else {
                i++;j--;
            }
        }

        return true;
    }
};