// https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150
// 101. Symmetric Tree

// Intuition
// To check if a binary tree is symmetric, we need to compare its left subtree and right subtree. 
// To do this, we can traverse the tree recursively and compare the left and right subtrees at each level. 
// If they are symmetric, we continue the traversal. Otherwise, we can immediately return false.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return false;
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        
        if(!left && !right) {
            return true;
        }

        if(!left || !right) {
            return false;
        }        

        return (left->val == right->val) && isMirror(left->right, right->left) && isMirror(left->left, right->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while(!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();

            if(t1 == nullptr && t2 == nullptr) {
                continue;
            }
            if(t1 == nullptr || t2 == nullptr) {
                return false;
            }
            if(t1->val != t2->val) {
                return false;
            }

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};