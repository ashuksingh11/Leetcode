//622. Design Circular Queue
//https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    int capacity;
    int size;
    int front;
    vector<int> q;
    
    MyCircularQueue(int k) {
        capacity = k;
        q = vector<int>(k);
        front = size = 0;
        
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        
        int idx = (front + size) %capacity;
        q[idx] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        
        front = (front+1) % capacity;
        --size;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }        
        
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }        
        int idx = (front+size-1) % capacity;
        return q[idx];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};