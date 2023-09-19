// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-interview-150
// 199. Binary Tree Right Side View
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(!root) {
            return res;
        }

        // do level order traversal pushing first the right child then left
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            //visit all child
            for(int i=0; i<sz; i++) {
                TreeNode* child = q.front();
                q.pop();

                //since right is put first it is at 0
                if(i==0) {
                    res.push_back(child->val);
                }
                if(child->right){
                    q.push(child->right);
                }
                if(child->left) {
                    q.push(child->left);
                }
            }
        }

        return res;
    }
};