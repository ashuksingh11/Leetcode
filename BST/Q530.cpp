//https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150
//530. Minimum Absolute Difference in BST

// Input: root = [4,2,6,1,3]
// Output: 1

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int mindiff = INT_MAX;
        int prevval = -1;
        helper(root,prevval,mindiff);

        return mindiff;
    }

    // use inorder traversal 
    void helper(TreeNode* root, int&prevval, int& mindiff) {
        if(root == nullptr) {
            return;
        }

        helper(root->left, prevval, mindiff);

        if(prevval !=-1) {
            mindiff = min(mindiff, root->val - prevval);

        }
        prevval = root->val;
        helper(root->right, prevval, mindiff);
    }

};