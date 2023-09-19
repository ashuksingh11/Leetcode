//https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150
//102. Binary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelsize = q.size();
            vector<int> temp;

            for(int i=0; i<levelsize; i++) {
                
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};