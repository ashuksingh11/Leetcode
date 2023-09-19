//941. Valid Mountain Array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        int i=0;
        
        while(i+1<size && arr[i] < arr[i+1]) {
            ++i;
        }
        
        if(i==0 || i== size-1) {
            return false;
        }
        
        while(i+1<size && arr[i] > arr[i+1]) {
            i++;
        }
        
        return i==size-1;
    }
};