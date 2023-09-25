//https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root == nullptr || (!root->left && !root->right)) {
         return 1;
     }
     
     int sum=0;
     if(root->left) {
         sum += root->left->data;
     }
     
     if(root->right) {
         sum += root->right->data;
     }
     
     return (sum == root->data) && isSumProperty(root->left) && isSumProperty(root->right);

    }
};