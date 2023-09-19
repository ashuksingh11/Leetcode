//250. Count Univalue Subtrees
//https://leetcode.com/problems/count-univalue-subtrees/description/

class Solution {
public:
    int count;
    bool dfs(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }

        bool isleftunival = dfs(root->left);
        bool isrightunival = dfs(root->right);
        
        // If both the children form uni-value subtrees, we compare the value of
        // chidren's node with the node value.
        if(isleftunival && isrightunival) {
            if(root->left && root->val != root->left->val) {
                return false;
            }
            if(root->right && root->val != root->right->val) {
                return false;
            }

            count++;
            return true;            
        }

        // Else if any of the child does not form a uni-value subtree, the subtree
        // rooted at node cannot be a uni-value subtree.
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        count = 0;
        dfs(root);

        return count;
    }
};
