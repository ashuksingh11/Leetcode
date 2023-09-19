//https://leetcode.com/problems/inorder-successor-in-bst/description/
//285. Inorder Successor in BST

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        while(root) {

            if(p->val >= root->val) {
                root = root->right;
            }
            else {
                successor = root;
                root = root->left;
            }
        }
        return successor;

    }
};