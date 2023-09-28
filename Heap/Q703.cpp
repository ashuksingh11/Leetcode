//703. Kth Largest Element in a Stream
//https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int nk;
    KthLargest(int k, vector<int>& nums) {
        nk = k;
        for(auto n:nums) {
            pq.push(n);
        }
        
        while(pq.size() > k) {
            pq.pop();
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > nk) {
            pq.pop();
        }
        
        return pq.top();
    }
};