//https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> res;
    if(root == nullptr) {
        return res;
    }
    
    deque<Node*> q;
    q.push_back(root);
    bool lefttoright = true;
    
    while(!q.empty()) {
        int s = q.size();
        for(int i=0; i<s; i++) {
            if(!lefttoright) {
                
                if(q.front()->left) {
                    q.push_back(q.front()->left);
                }
                if(q.front()->right) {
                    q.push_back(q.front()->right);
                }
                res.push_back(q.front()->data);
                q.pop_front();
            }
            else {
                if(q.back()->right) {
                    q.push_front(q.back()->right);    
                }
                
                if(q.back()->left) {
                    q.push_front(q.back()->left);
                }
                res.push_back(q.back()->data);
                q.pop_back();
            }
        }
        lefttoright = !lefttoright;
    }
    
    return res;
}