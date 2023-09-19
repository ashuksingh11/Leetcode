//145. Binary Tree Postorder Traversal


class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }

        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);

        return ans;
    }
};

//iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)        return ans;
        stack<TreeNode*> s1, s2;

        s1.push(root);
        while(!s1.empty()){
            TreeNode *curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left != NULL)
                s1.push(curr->left);
            if(curr->right != NULL)
                s1.push(curr->right);
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};