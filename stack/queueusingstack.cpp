//https://www.geeksforgeeks.org/queue-using-stacks/
class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        if(input.empty() && output.empty()) {
            return -1;
        }
        
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int ret = output.top();
        output.pop();
        return ret;
    }
};