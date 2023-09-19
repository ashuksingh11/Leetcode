//201. Bitwise AND of Numbers Range
//https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while(left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};