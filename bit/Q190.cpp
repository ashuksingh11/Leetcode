// https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150
// 190. Reverse Bits
// Reverse bits of a given 32 bits unsigned integer.

// use example n= 1101, we are just extracting last bit setting to ans , right shift n
// and left shift ans
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++) {
            ans = ans << 1;
            bool bit = n & 1;
            ans = ans | bit;
            n = n >> 1;
            //cout << bit << " ";
        }
        return ans;
    }
};

//efficient

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

//abcdefgh -> efghabcd -> ghefcdab -> hgfedcba