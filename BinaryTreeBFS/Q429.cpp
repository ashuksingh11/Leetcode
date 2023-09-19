//429. N-ary Tree Level Order Traversal
//https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == nullptr) {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for(auto& child : curr->children) {
                    q.push(child);
                }
            }
            result.push_back(level);
        }

        return result;
    }
};
