//https://www.geeksforgeeks.org/implement-stack-using-queue/

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        
        while(!q1.empty()) {
            q2.push(q1.front());;
            q1.pop();
        }
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty()) {
            return -1;
        }
        
        int ret = q1.front();
        q1.pop();
        
        return ret;
}