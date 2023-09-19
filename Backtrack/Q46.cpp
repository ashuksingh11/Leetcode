//46. Permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;

        permute(ans,curr,nums);

        return ans;
    }

    void permute(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(auto num: nums) {
            if(find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                permute(ans, curr, nums);
                curr.pop_back();
            }
        }
    }
};

//string permutation

// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;
 
// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string& a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l + 1, r);
 
            // backtrack
            swap(a[l], a[i]);
        }
    }
}
 
// Driver Code
int main()
{
    string str = "ABC";
    int n = str.size();
 
    // Function call
    permute(str, 0, n - 1);
    return 0;
}