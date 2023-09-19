//https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i =0; i<n; i++) {
            temp[(i+k)%n] = nums[i];
        }

        nums=temp;
    }
};

// Approach
// Example:-1234567 ,k=3
// 1.first reverse the numbers form index 0 to n-k;
// ->4321 567
// 2.reverse the k elements from the last
// ->4321 765
// 3.now reverse the whole nums;
// ->5671234 Done Answer is here !!!!
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l=nums.size();
        k%=l; // if k > than l
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());      
    }
};


