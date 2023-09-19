//https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150
//6. Zigzag Conversion
// P   A   H   N
// A P L S I I G
// Y   I   R
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

class Solution {
public:
    string convert(string s, int numRows) {
        // for all rows we need to jump or inlcude (numRows-1)*2
        // except for first and last rows we need to include 
        // (numRows - 2*i) char where i is row num

        //base case
        if (numRows == 1) return s;

        string result="";
        int jumps = (numRows - 1)*2;
        for(int i=0; i < numRows; i++) {
            for(int j = i; j < s.size(); j+= jumps){
                result += s[j];
                if(i>0 && i<numRows-1 && (j+jumps-2*i) < s.size()){
                    result += s[j+jumps-2*i];
                }
            }

        }

        return result;
    }
};