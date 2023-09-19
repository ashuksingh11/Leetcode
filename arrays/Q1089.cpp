//1089. Duplicate Zeros
//https://leetcode.com/problems/duplicate-zeros/description/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int possibledups = 0;
        int len = arr.size()-1;

        for(int i=0; i<=len-possibledups; i++) {
            if(arr[i] == 0) {
                if(i == len-possibledups) {
                    //last posible is 0 which can't be duplicated
                    arr[len] = 0;
                    len--;
                    break;
                }
                possibledups++;
            }
        }

        int last = len-possibledups;
        for(int i=last; i>= 0; i--) {
            if(arr[i] != 0) {
                arr[i+possibledups] = arr[i];
            }
            else {
                arr[i+possibledups] = 0;
                possibledups--;
                arr[i+possibledups] = 0;
            }
        }
    }
};