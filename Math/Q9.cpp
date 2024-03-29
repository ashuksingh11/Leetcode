//9. Palindrome Number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x!=0)) {
            return false;
        }

        int revertednum = 0;
        while(x > revertednum) {
            revertednum = revertednum * 10 + x%10;
            x = x/10;
        }

        return x==revertednum || x==revertednum/10;

    }
};