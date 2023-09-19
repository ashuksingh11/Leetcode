//215. Kth Largest Element in an Array
//https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> pq(nums.begin()
        , nums.begin()+k);

        for(int i=k; i<nums.size(); i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};