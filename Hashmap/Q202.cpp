//https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150
//202. Happy Number
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

//find new number by finding square of each digit and adding them
// try to to add this number to set if it fails or becomes 1 then break and return true
class Solution {
public:
    int nextNumber(int n) {
        int newnumber = 0;

        while(n != 0) {
            int digit = n%10;
            newnumber += digit*digit;
            n = n/10;
        }

        return newnumber;
    }

    bool isHappy(int n) {
        unordered_set<int> us;

        while(n!=1 && us.count(n)==0) {
            us.insert(n);
            n = nextNumber(n);
        }

        return n==1;
        
    }
};