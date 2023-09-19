//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
//104. Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        return max(maxLeft, maxRight)+1;
    }
};