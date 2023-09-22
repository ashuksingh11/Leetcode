//https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> res;
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty()) {
           int n = q.size();
           for(int i=0; i<n; i++) {
               Node* frontnode = q.front();
               q.pop();
               
               if(i == n-1) {
                   res.push_back(frontnode->data);
               }
               
               if(frontnode->left) {
                   q.push(frontnode->left);
               }
               if(frontnode->right) {
                   q.push(frontnode->right);
               }
           }
       }
       
       return res;
    }
};