//662. Maximum Width of Binary Tree
//https://leetcode.com/problems/maximum-width-of-binary-tree/description/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int maxwidth = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            int qsize = q.size();
            int lindex = q.front().second;
            int rindex = q.back().second;
            
            maxwidth = max(maxwidth, rindex-lindex+1);
            
            for(int i=0; i<qsize; i++) {
                TreeNode* temp = q.front().first;
                int nindex = q.front().second - lindex;
                q.pop();
                
                if(temp->left) {
                    q.push({temp->left, 2LL*nindex+1});
                }
                
                if(temp->right) {
                    q.push({temp->right, 2LL*nindex+2});
                }
                
            }
        }
        
        return maxwidth;
    }
};