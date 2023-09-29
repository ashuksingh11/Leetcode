//https://www.geeksforgeeks.org/find-pair-given-sum-bst/
class Solution {
public:
    vector<int> ino;
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        
        inorder(root);
        int i=0 , j=ino.size()-1;
        while(i<j) {
            if(ino[i] + ino[j] > k) {
                --j;
            }
            else if(ino[i]+ino[j]<k) {
                ++i;
            }
            else {
                return true;
            }
        }
        
        return false;
        
    }
    
    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }
        
        inorder(root->left);
        ino.push_back(root->val);
        inorder(root->right);
        
    }
};