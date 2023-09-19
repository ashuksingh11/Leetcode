//https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
//58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        //start from end and find first occurence of non space char
        // set flag once space found then break when another is found again
        //counting in between
        int count = 0;
        bool flag = false;

        for(int i=s.size()-1; i>=0; i--) {

            if(s[i] != ' ') {
                count++;
                flag = true;
            }

            if(s[i] == ' ' && flag) {
                break;
            }
        }

        return count;
    }
};