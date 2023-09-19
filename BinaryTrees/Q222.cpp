//222. Count Complete Tree Nodes

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

//there exists a solution which is O(logn) using binary search