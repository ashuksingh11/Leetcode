//137. Single Number II
//https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int loner = 0;
        for(int shift=0; shift<32; shift++) {
            int bitsum = 0;

            for(int n:nums){
                bitsum += (n >> shift) & 1;
            }

            int lonerbit = bitsum % 3;
            loner = loner | (lonerbit << shift);
        }

        return loner;
    }
};