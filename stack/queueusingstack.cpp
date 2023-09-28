//https://www.geeksforgeeks.org/queue-using-stacks/
class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
        if(s1.empty() && s2.empty()) {
            return -1;
        }
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int ret = s2.top();
        s2.pop();
        
        return ret;
        
    }
    
    int peek() {
        if(s1.empty() && s2.empty()) {
            return -1;
        }
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int ret = s2.top();
        
        return ret;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};