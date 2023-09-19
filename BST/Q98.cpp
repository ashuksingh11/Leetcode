// https://leetcode.com/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150
// 98. Validate Binary Search Tree

class Solution {
public:

    void inorder(TreeNode* root, vector <int> &nodes)
    {
        if(!root)
            return;

        inorder(root -> left, nodes);
        nodes.push_back(root -> val);    
        inorder(root -> right, nodes); 
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return true;

        vector <int> nodes;
        inorder(root, nodes); 

        set <int> s(nodes.begin(), nodes.end());

        if(s.size() != nodes.size())
            return false;

        for(int i = 0; i < nodes.size()-1; i++)
        {
            if(nodes[i] > nodes[i+1])
                return false;
        }       

        return true;
    }
};

//////////
class Solution {
public:
    TreeNode* prev;
    bool helper(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }

        if(!helper(root->left)) {
            return false;
        }

        if(prev && root->val <= prev->val) {
            return false;
        }
        prev = root;

        return helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        prev = nullptr;
        return helper(root);
    }
};