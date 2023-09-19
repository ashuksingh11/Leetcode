// https://leetcode.com/problems/path-sum/description/?envType=study-plan-v2&envId=top-interview-150
// 112. Path Sum
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }

        //reached leaf node check if target sum has reached
        if(root->left == nullptr && root->right==nullptr && root->val - targetSum == 0) {
            return true;
        }

        int left = hasPathSum(root->left, targetSum - root->val);
        int right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
};