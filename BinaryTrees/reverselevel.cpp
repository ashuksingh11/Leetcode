//https://www.geeksforgeeks.org/reverse-level-order-traversal/
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> res;
    if(root == nullptr) {
        return res;
    }
    
    queue<Node*> q;
    q.push(root);
    stack<int> st;
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; i++) {
            Node* t = q.front();
            q.pop();
            
            st.push(t->data);
            if(t->right) {
                q.push(t->right);
            }
            if(t->left) {
                q.push(t->left);
            }
        }
    }
    
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    
    return res;
}