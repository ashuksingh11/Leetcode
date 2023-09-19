// https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
// 226. Invert Binary Tree

// Intuition
// In this question we have to Invert the binary tree.
// So we use Post Order Treversal in which first we go in Left subtree and then in Right subtree then we return back to Parent node.
// When we come back to the parent node we swap it's Left subtree and Right subtree.

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //do a post order traveersal and swap left subtree with righ
        //base case
        if(root == nullptr) {
            return nullptr;
        }

        invertTree(root->left); //traverse left subtree
        invertTree(root->right); //traverse right subtree

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};