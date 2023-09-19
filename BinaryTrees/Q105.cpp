//105. Construct Binary Tree from Preorder and Inorder Traversal
// preorder means Root left right, so 
class Solution {
public:
    int preorderIndex;
    unordered_map<int,int> inordermap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for(int i=0; i<inorder.size(); i++) {
            inordermap[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, preorder.size()-1);
    }

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }

        int rootval = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootval);

        root->left = arrayToTree(preorder, left, inordermap[rootval] - 1);
        root->right = arrayToTree(preorder, inordermap[rootval]+1, right);

        return root;
    }
};