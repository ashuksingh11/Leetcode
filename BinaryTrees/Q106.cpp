//106. Construct Binary Tree from Inorder and Postorder Traversal
// msae as preoder just postorder root value is at last

class Solution {
public:
    int postorderIndex;
    unordered_map<int,int> inordermap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;
        for(int i=0; i<inorder.size(); i++) {
            inordermap[inorder[i]] = i;
        }

        return helper(postorder, 0 , postorder.size()-1);
    }

    TreeNode* helper(vector<int>& postorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootval = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootval);

        root->right = helper(postorder, inordermap[rootval]+1, right);
        root->left = helper(postorder, left, inordermap[rootval] - 1);

        return root;
    }
};