//461. Hamming Distance
//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xxory = x^y;
        while(xxory > 0) {
            count++;
            xxory = xxory & (xxory-1);
        }
        
        return count;
    }
};