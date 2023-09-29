//917. Reverse Only Letters
//https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0, r=s.size()-1;
        
        while(l<r)  {
            if(!isenglish(s[l])) {
                ++l;
            }
            else if(!isenglish(s[r])) {
                --r;
            }
            else {
                swap(s[l],s[r]);
                ++l;--r;
            }
        }
        
        return s;
    }
    
    bool isenglish(char ch) {
        int i = tolower(ch) - 'a';
        return (i>=0 && i<=26) ? true:false;
    }
};
