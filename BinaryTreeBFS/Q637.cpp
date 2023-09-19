// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
// 637. Average of Levels in Binary Tree
// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        //do BFS and find avg at each level
        vector<double> res;
        if(!root) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelsize = q.size();
            double sum = 0;
            for(int i=0; i<levelsize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            double avg = sum/levelsize;
            res.push_back(avg);
        }

        return res;
    }
};