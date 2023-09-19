//295. Find Median from Data Stream
//https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150

class MedianFinder {
    priority_queue<int> lo; //max heap
    priority_queue<int, vector<int>, greater<int>> hi; //min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if(lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? lo.top() : (lo.top()+hi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
