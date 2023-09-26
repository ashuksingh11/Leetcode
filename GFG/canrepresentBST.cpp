//https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int> st;
        st.push(arr[0]);
        
        int root = INT_MIN;
        
        for(int i=0; i<N; i++) {
            if(arr[i] < root) {
                return 0;
            }    
            
            while(!st.empty() && st.top() < arr[i]) {
                root = st.top();
                st.pop();
            }
            
            st.push(arr[i]);
        }
        
        return 1;
    }
};