//https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150
//155. Min Stack
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// use two stacks s1 and s2 , put val in s2 only if s2 i empty or val is less 
// than top of s2.

class MinStack {
public:
    MinStack() {
        
    }
    stack<int>s1;
    stack<int>s2;
    
    void push(int val) {
        s1.push(val);
        if(s2.size()==0 || val<=s2.top())
        {
            s2.push(val);
        }
    }
    
    void pop() {
        int ans=s1.top();
        s1.pop();
        if(ans==s2.top())
            s2.pop();
    }
    
    int top() {
        if(s1.size()==0)
        {
            return -1;
        }
        return s1.top();
        
    }
    
    int getMin() {
        if(s2.size()==0)
            return 0;
        int n=s2.top();
        return n;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */