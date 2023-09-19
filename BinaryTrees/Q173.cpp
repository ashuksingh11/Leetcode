//173. Binary Search Tree Iterator

class BSTIterator {
public:
    vector<int> sortedarr;
    int currindex;
    BSTIterator(TreeNode* root) {
        currindex = -1;
        inorder(root);
    }

    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        inorder(root->left);
        sortedarr.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        return sortedarr[++currindex];
    }
    
    bool hasNext() {
        return (currindex+1) < sortedarr.size();
    }
};