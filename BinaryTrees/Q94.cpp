//94. Binary Tree Inorder Traversal

class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }

        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);

        return ans;
    }
};


//iterative
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != nullptr || !st.empty()) {
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }

        return ans;
    }
};