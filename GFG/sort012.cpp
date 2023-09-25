//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int lo = 0;
        int mid = 0;
        int hi = n-1;
        
        while(mid <= hi) {
            if(a[mid] == 0) {
                swap(a[lo++], a[mid++]);
            }
            else if(a[mid] == 1) {
                mid++;
            }
            else {
                swap(a[mid], a[hi--]);
            }
        }
    }
    
};