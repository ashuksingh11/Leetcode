//https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum
/*You are required to complete below method */
long long sumUtil(Node* root, int val) {
    if(root == nullptr) {
        return 0;
    }
    
    val = val*10 + root->data;
    
    if(root->left == nullptr && root->right == nullptr) {
        return val;
    }
    
    long long lsum = sumUtil(root->left, val);
    long long rsum = sumUtil(root->right, val);
    
    return lsum+rsum;
}
long long treePathsSum(Node *root)
{
    //Your code here
    return sumUtil(root, 0);
}