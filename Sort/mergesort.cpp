//mergesort sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temparr(nums.size());
        mergeSort(nums,0, nums.size()-1, temparr);

        return nums;

    }

    void mergeSort(vector<int>& arr, int left, int right, vector<int>& temparr) {
        if(left >= right) {
            return;
        }

        int mid = (left+right)/2;
        mergeSort(arr, left,mid, temparr);
        mergeSort(arr, mid+1, right, temparr);

        merge(arr, left,mid, right, temparr);
    }

    void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temparr) {
        //calc start and sizes of arr to be merged
        int start1 = left;
        int start2 = mid+1;
        int n1 = mid-left+1;
        int n2 = right - mid;

        //copy elements in temp arr
        for(int i=0; i<n1; i++) {
            temparr[start1+i] = arr[start1+i];
        }

        for(int i=0;i<n2;i++) {
            temparr[start2+i] = arr[start2+i];
        }

        int i=0, j=0,k=left;
        while(i<n1 && j<n2) {
            if(temparr[start1+i] <= temparr[start2+j]) {
                arr[k] = temparr[start1+i];
                i++;
            }
            else {
                arr[k] = temparr[start2+j];
                j++;
            }
            k++;
        }

        while(i<n1) {
            arr[k] = temparr[start1+i];
            i++;k++;
        }
        while(j<n2) {
            arr[k] = temparr[start2+j];
            j++;k++;
        }
    }
};