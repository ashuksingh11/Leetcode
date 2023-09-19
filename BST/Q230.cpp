//https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/?envType=study-plan-v2&envId=top-interview-150
//230. Kth Smallest Element in a BST

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

class Solution {
public:
    int ans;
    void inorder(TreeNode* root, int& k) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, k);
        if(--k == 0) {
            ans = root->val;
        }

        inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);

        return ans;
    }
};