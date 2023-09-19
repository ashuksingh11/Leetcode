//102. Binary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> ans;
    void helper(TreeNode* root, int depth) {
        if(root == nullptr) {
            return;
        }

        if(ans.size() == depth) {
            ans.push_back(vector<int>());
        }

        ans[depth].push_back(root->val);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0 );
        return ans;    
    }
};

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> res;
            for(int i=0; i<size; i++) {
                TreeNode* item = q.front();
                q.pop();
                res.push_back(item->val);

                if(item->left) {
                    q.push(item->left);
                }
                if(item->right) {
                    q.push(item->right);
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};