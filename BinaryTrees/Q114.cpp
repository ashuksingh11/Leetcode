//114. Flatten Binary Tree to Linked List
class Solution {
public:
    TreeNode* helper(TreeNode* node) {
        if (node == nullptr) {
            return node;
        }

        //leaf node simply return node
        if(node->left == nullptr && node->right == nullptr) {
            return node;
        }

        TreeNode* lefttail = helper(node->left);
        TreeNode* righttail = helper(node->right);

        //if there was left subtree, we shuffle so there is nothing
        //around leeft
        if(lefttail) {
            lefttail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }

        //return rightmost node
        return (righttail == nullptr)?lefttail : righttail;
    }

    void flatten(TreeNode* root) {
        helper(root);
    }
};