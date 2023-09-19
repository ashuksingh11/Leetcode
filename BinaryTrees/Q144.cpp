//144. Binary Tree Preorder Traversal
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);

        return ans;
    }
};

//Iterative
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> iStack;
        iStack.push(root);

        while(!iStack.empty()) {
            TreeNode* curr = iStack.top();
            iStack.pop();
            if(curr != nullptr) {
                ans.push_back(curr->val);
                iStack.push(curr->right);
                iStack.push(curr->left);
            }

        }

        return ans;
    }
};