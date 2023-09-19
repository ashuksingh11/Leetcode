//https://leetcode.com/problems/number-of-1-bits/submissions/?envType=study-plan-v2&envId=top-interview-150
//191. Number of 1 Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // AND of n & n-1 makes LSB 1 to zero 
        // so number of times it takes to make num 0 is num of 1's
        int ones = 0;
        while(n != 0) {
            ones++;
            n = n & (n-1);
        }

        return ones;
    }
};