//https://www.geeksforgeeks.org/next-greater-element/
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>ans;
        stack<long long>st;
        for(int i=n-1;i>=0;i--){
            while( !st.empty() and arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
               
            }
            else{
                ans.push_back(arr[st.top()]);
            }
             st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};