//124. Binary Tree Maximum Path Sum

class Solution {
public:
    int maxsum;

    int gainfromsubtree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftgain = max(gainfromsubtree(root->left), 0);
        int rightgain = max(gainfromsubtree(root->right), 0);

        maxsum = max(maxsum, leftgain + rightgain + root->val);

        return max(leftgain+root->val, rightgain+root->val);
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        gainfromsubtree(root);

        return maxsum;
    }
};