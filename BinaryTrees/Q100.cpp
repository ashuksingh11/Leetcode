// https://leetcode.com/problems/same-tree/submissions/?envType=study-plan-v2&envId=top-interview-150
// 100. Same Tree

// Approach
// Check the base case: if both trees are null, return true.
// Check if only one tree is null or the values of the current nodes are different, return false.
// Recursively check if the left subtrees of both trees are identical.
// Recursively check if the right subtrees of both trees are identical.
// Return the logical AND of the results from steps 3 and 4.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //if both node are null they are identical
        if(p==nullptr && q==nullptr) {
            return true;
        }

        if(p==nullptr || q==nullptr) {
            return false;
        }

        if(p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
};