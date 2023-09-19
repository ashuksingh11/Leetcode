// heap sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();
        //build heap
        for(int i=n/2-1; i>=0; i--) {
            heapify(arr, n, i);
        }

        //traverse elements one by one, to move current root to end, and
        for(int i=n-1; i>=0; i--) {
            swap(arr[0], arr[i]);
            //call max heapify on reduced heap
            heapify(arr, i, 0);
        }
    }

    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        //if left child is greater than parent
        if(left<n && arr[left] > arr[largest]) {
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr,n,largest);
        }
    }
};