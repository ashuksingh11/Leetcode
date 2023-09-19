//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
//236. Lowest Common Ancestor of a Binary Tree

//https://www.youtube.com/watch?v=cOjLyASDJcc

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }

        if(p == root || q==root) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right, p,q);

        if (left == nullptr) {
            return right;
        }
        else if (right == nullptr) {
            return left;
        }        

        return root;
    }
};