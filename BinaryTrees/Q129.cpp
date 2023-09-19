//129. Sum Root to Leaf Numbers

class Solution {
public:
    int roottoleaf;
    void helper(TreeNode* node, int currnum) {
        if(node == nullptr) {
            return;
        }

        currnum = 10*currnum + node->val;

        //if leaf update root-to-leaf
        if(node->left == nullptr && node->right == nullptr) {
            roottoleaf += currnum;
        }

        helper(node->left, currnum);
        helper(node->right, currnum);
    }

    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return roottoleaf;
    }
};